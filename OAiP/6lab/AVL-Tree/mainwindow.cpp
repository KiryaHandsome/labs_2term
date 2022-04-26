#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->arrayWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    connect(ui->AddButton, SIGNAL(clicked()), this, SLOT(AddButton_clicked()));
    connect(ui->PrintButton, SIGNAL(clicked()), this, SLOT(PrintButton_clicked()));
    connect(ui->DeleteButton, SIGNAL(clicked()), this, SLOT(DeleteButton_clicked()));
    connect(ui->FindButton, SIGNAL(clicked()), this, SLOT(FindButton_clicked()));
    connect(ui->InputButton, SIGNAL(clicked()), this, SLOT(InputButton_clicked()));
    connect(ui->AddCellButton, SIGNAL(clicked()), this, SLOT(AddCellButton_clicked()));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateTable()));
    connect(ui->VisualizationButton, SIGNAL(clicked()), this, SLOT(drawTree()));
    connect(ui->NumOfNodesButton, SIGNAL(clicked()), this, SLOT(NumOfNodes()));
    connect(ui->ClearButton, SIGNAL(clicked()), this, SLOT(ClearArrayTable()));

    window = new VisualTree();
    window->setTree(&tree);
    //window->hide();

}

MainWindow::~MainWindow()
{
    delete window;
    delete ui;
}

void MainWindow::AddButton_clicked()
{
    QString key = ui->Add_KeyEdit->text();
    QString info = ui->Add_InfoEdit->text();

    if(key == "" || info == ""){
        QString text = "Пустая строка: " + QString(key == "" ? "Ключ." : "Информация.");
        QMessageBox::information(this, "Уведомление", text);
        return;
    }

    int key_value = key.toInt();
    if(key_value == 0 && key != "0"){
        QMessageBox::warning(this, "Ошибка", "Некорректный ключ.");
        return;
    }

    std::string info_value = info.toStdString();
    tree.insert(key_value, info_value);
    QMessageBox::information(this, "Уведомление", "Запись добавлена успешно.");
    //clear line edits
    ui->Add_KeyEdit->clear();
    ui->Add_InfoEdit->clear();

    updateTable();
}

void MainWindow::DeleteButton_clicked()
{
    QString key = ui->DeleteEdit->text();
    if(key == ""){
        QMessageBox::information(this, "Уведомление", "Пустая строка ввода.");
        return;
    }

    int key_value = key.toInt();
    if(key_value == 0 && key != "0"){
        QMessageBox::warning(this, "Ошибка", "Некорректный ключ.");
        return;
    }

    tree.deleteNode(key_value);
    if(!tree.isLastDeletionSuccesfull()){
        QMessageBox::information(this, "Уведомление", "Узла с данным узлом не найдено.");
    }
    else {
        QMessageBox::information(this, "Уведомление", "Узел успешно удален.");
        ui->DeleteEdit->clear();
    }
    updateTable();
}

void MainWindow::FindButton_clicked()
{
    QString key = ui->FindEdit->text();
    if(key == "") {
        QMessageBox::information(this, "Уведомление", "Пустая строка ввода.");
    }
    else if(key.toInt() == 0 && key != '0'){
        QMessageBox::warning(this, "Ошибка", "Некорректный ключ.");
    }
    else {
        int key_value = key.toInt();
        std::string info = tree.search(key_value);
        if(info == ""){
            QMessageBox::information(this, "Уведомление", "Узла с данным ключом не найдено.");
        } else {
            QMessageBox::information(this, "Уведомление",
                                     QString::fromStdString("Информация в найденном узле: " + info));
            ui->FindEdit->clear();
        }
    }
}

void MainWindow::PrintButton_clicked()
{
    updateTable();
    if(tree.isEmpty()){
        QMessageBox::information(this, "Уведомление", "Дерево не содержит узлов.");
    }
}

void MainWindow::InputButton_clicked()
{
    int size = ui->arrayWidget->columnCount();
    if(size == 0){
        QMessageBox::information(this, "Уведомление", "Массив пуст.\nСперва добавьте ячейки в массив.");
        return;
    }
    bool isCorrectArr = true;
    std::vector<std::pair<int, std::string>> input_array;
    for(int i = 0; i < size; ++i){
        QString key = ui->arrayWidget->item(0, i)->text();
        QString info = ui->arrayWidget->item(1, i)->text();
        ui->arrayWidget->item(0, i)->setBackgroundColor(QColor(255, 255, 255));
        ui->arrayWidget->item(1, i)->setBackgroundColor(QColor(255, 255, 255));
        if(key == "" ||  info == ""
                || (key.toInt() == 0 && key != "0")){
            ui->arrayWidget->item(0, i)->setBackgroundColor(QColor(255, 0, 0));
            ui->arrayWidget->item(1, i)->setBackgroundColor(QColor(255, 0, 0));
            isCorrectArr = false;
            input_array.push_back(std::make_pair(0, ""));
        }
        else if(tree.search(key.toInt()) != ""){
            ui->arrayWidget->item(0, i)->setBackgroundColor(QColor(255, 255, 0));
            ui->arrayWidget->item(1, i)->setBackgroundColor(QColor(255, 255, 0));
            isCorrectArr = false;
            input_array.push_back(std::make_pair(0, ""));
        } else {
            for(size_t j = 0; j < input_array.size(); ++j){
                if(key.toInt() == input_array[j].first){
                    ui->arrayWidget->item(0, j)->setBackgroundColor(QColor(0, 255, 0));
                    ui->arrayWidget->item(1, j)->setBackgroundColor(QColor(0, 255, 0));
                    ui->arrayWidget->item(0, i)->setBackgroundColor(QColor(0, 255, 0));
                    ui->arrayWidget->item(1, i)->setBackgroundColor(QColor(0, 255, 0));
                    isCorrectArr = false;
                }
            }
            input_array.push_back(std::make_pair(key.toInt(), info.toStdString()));
        }

    }
    if(!isCorrectArr){
        QMessageBox::warning(this, "Ошибка", "Есть некорректные значения в ячейках.\n"
                                             "Красный - некорректный ключ или пустая ячейка\n"
                                             "Желтый - такой ключ уже в дереве\n"
                                             "Зеленый - одинаковые ключи в массиве");
    } else {
        tree.addInfoFromArray(input_array);
        QMessageBox::information(this, "Уведомление", "Данные из массива добавлены успешно.");
        ui->arrayWidget->setColumnCount(0);
    }

    updateTable();
}

void MainWindow::AddCellButton_clicked()
{
    ui->arrayWidget->insertColumn(ui->arrayWidget->columnCount());
    ui->arrayWidget->setItem(0, ui->arrayWidget->columnCount() - 1, new QTableWidgetItem(""));
    ui->arrayWidget->setItem(1, ui->arrayWidget->columnCount() - 1, new QTableWidgetItem(""));
}

void MainWindow::ClearArrayTable()
{
    ui->arrayWidget->setColumnCount(0);
}

void MainWindow::updateTable()
{
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Ключ" << "Информация");
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int index = ui->comboBox->currentIndex();
    switch(index)
    {
    case 0: tree.printPreOrder(); break;
    case 1: tree.printPostOrder(); break;
    case 2: tree.printInOrder(); break;
    }

    auto traverseArray = tree.getLastTraverseArray();
    for(size_t i = 0; i < traverseArray.size(); ++i)
    {
        QString key = QString::number(traverseArray[i].first);
        QString info = QString::fromStdString(traverseArray[i].second);
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(key));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(info));
    }
}

void MainWindow::drawTree()
{
    if(!tree.isEmpty()){
        window->drawTree();
        window->show();
    } else {
        QMessageBox::information(this, "Уведомление", "Дерево не содержит узлов.");
    }

}

void MainWindow::NumOfNodes()
{
    int num = tree.numberOfNodesWithOneChild();
    QMessageBox::information(this, "Ответ", "Число узлов-родителей с одним ребенком: " + QString::number(num));
}



