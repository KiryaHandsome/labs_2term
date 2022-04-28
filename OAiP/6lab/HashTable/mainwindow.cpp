#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

const int TABLES_SIZE = 100;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), leftTable(TABLES_SIZE), rightTable(TABLES_SIZE)
{
    ui->setupUi(this);

    ui->tableWidget_1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget_1->setRowCount(100);
    ui->tableWidget_2->setRowCount(100);

    ui->tableWidget_2->setVisible(false);
    ui->LeftTableButton->setVisible(false);
    ui->RightTableButton->setVisible(false);


    connect(ui->AddButton, SIGNAL(clicked()), this, SLOT(AddToTable()));
    connect(ui->RemoveButton, SIGNAL(clicked()), this, SLOT(RemoveFromTable()));
    connect(ui->SearchButton, SIGNAL(clicked()), this, SLOT(SearchInTable()));
    connect(ui->Create2TablesButton, SIGNAL(clicked()), this, SLOT(Create2Tables()));

    createTable();
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createTable()
{
    for(int i = 0; i < 100; ++i){
        char sign = (qrand() % 2 == 0 ? -1 : 1);
        leftTable.insert(sign * (qrand() % 50), qrand());
    }

    printLeftTable();
}

void MainWindow::AddToTable()
{
    QString key = ui->Add_KeyEdit->text();
    QString value = ui->Add_ValueEdit->text();
    if(key == "" || value == ""){
        QMessageBox::warning(this, "Ошибка", "Есть пустые поля ввода.");
        return;
    }
    if((key.toInt() == 0 && key != "0") || (value.toInt() == 0 && key != "0")){
        QMessageBox::warning(this, "Ошибка", "Данные в полях должны быть целочисленными.");
        return;
    }
    if(ui->RightTableButton->isChecked()){
        if(rightTable.isFull()){
            QMessageBox::warning(this, "Ошибка", "Правая таблица переполнена.");
            return;
        }
        if(!rightTable.insert(key.toInt(), value.toInt())){
            QMessageBox::warning(this, "Ошибка", "Элемент с данным ключом уже в таблице.");
            return;
        } else {
            QMessageBox::information(this, "Уведомление", "Элемент успешно добавлен.");
            printRightTable();
        }
    }
    else {
        if(leftTable.isFull()){
            QMessageBox::warning(this, "Ошибка", "Левая таблица переполнена.");
            return;
        }
        if(!leftTable.insert(key.toInt(), value.toInt())){
            QMessageBox::warning(this, "Ошибка", "Элемент с данным ключом уже в таблице.");
            return;
        } else {
            QMessageBox::information(this, "Уведомление", "Элемент успешно добавлен.");
            printLeftTable();
        }
    }

    ui->Add_KeyEdit->clear();
    ui->Add_ValueEdit->clear();
}

void MainWindow::RemoveFromTable()
{
    QString key_str = ui->RemoveEdit->text();
    if(key_str == ""){
        QMessageBox::warning(this, "Ошибка", "Пустое поле ввода.");
        return;
    }
    else if(key_str.toInt() == 0 && key_str != "0"){
        QMessageBox::warning(this, "Ошибка", "Данные в полe должны быть целочисленными.");
        return;
    }

    int key = key_str.toInt();
    if(ui->RightTableButton->isChecked()){
        if(rightTable.remove(key)){
            QMessageBox::information(this, "Уведомление", "Элемент успешно удален.");
            printRightTable();
            ui->RemoveEdit->clear();
        }
        else {
            QMessageBox::information(this, "Уведомление", "Элемента с данным ключом не найдено.");
        }
    }
    else {
        if(leftTable.remove(key)){
            QMessageBox::information(this, "Уведомление", "Элемент успешно удален.");
            printLeftTable();
            ui->RemoveEdit->clear();
        }
        else {
            QMessageBox::information(this, "Уведомление", "Элемента с данным ключом не найдено.");
        }
    }
}

void MainWindow::SearchInTable()
{
    QString key_str = ui->SearchEdit->text();

    if(key_str == ""){
        QMessageBox::warning(this, "Ошибка", "Пустое поле ввода.");
        return;
    }
    else if(key_str.toInt() == 0 && key_str != "0"){
        QMessageBox::warning(this, "Ошибка", "Данные в полe должны быть целочисленными.");
        return;
    }

    int key = key_str.toInt();
    if(ui->RightTableButton->isChecked()){
        int res = rightTable.search(key);
        if(res != INT_MIN){
            QMessageBox::information(this, "Уведомление", "Элемент с данным ключом: " + QString::number(res));
        }
        else {
            QMessageBox::information(this, "Уведомление", "Элемента с данным ключом не найдено.");
        }
    }
    else {
        int res = leftTable.search(key);
        if(res != INT_MIN){
            QMessageBox::information(this, "Уведомление", "Элемент с данным ключом: " + QString::number(res));
        }
        else {
            QMessageBox::information(this, "Уведомление", "Элемента с данным ключом не найдено.");
        }
    }

    ui->SearchEdit->clear();
}

void MainWindow::Create2Tables()
{
    ui->tableWidget_2->setVisible(true);
    ui->LeftTableButton->setVisible(true);
    ui->RightTableButton->setVisible(true);
    ui->Create2TablesButton->setVisible(false);

    auto table_array = leftTable.getHashTableArray();
    for(int i = 0; i < TABLES_SIZE; ++i){
        if(!table_array[i].empty()){
            if(table_array[i].top().first < 0){
                rightTable.insert(table_array[i].top().first, table_array[i].top().second);
                leftTable.remove(table_array[i].top().first);
            }
        }
    }

    printLeftTable();
    printRightTable();

    QMessageBox::information(this, "Уведомление", "Вторая таблица успешно создана.");
}

void MainWindow::printLeftTable()
{
    auto table_array = leftTable.getHashTableArray();
    //clear
    ui->tableWidget_1->setRowCount(0);
    ui->tableWidget_1->setRowCount(100);
    for(int i = 0; i < TABLES_SIZE; ++i){
        if(!table_array[i].empty()){

            vector<pair<int, int>> temp_vector;

            //get information from stack
            while(!table_array[i].empty()){
                temp_vector.push_back(table_array[i].top());
                table_array[i].pop();
            }

            for(auto it = temp_vector.rbegin(); it != temp_vector.rend(); ++it){
                table_array[i].push(*it);
            }


            size_t hash_key = leftTable.hash(table_array[i].top().first);
            qDebug() << table_array[i].top().first << table_array[i].top().second;
            QString key_text, value_text;
            for(size_t j = 0; j < temp_vector.size(); ++j){
                key_text += QString::number(temp_vector[j].first) + " ";
                value_text += QString::number(temp_vector[j].second) + " ";
            }

            ui->tableWidget_1->setItem(hash_key, 0, new QTableWidgetItem(key_text));
            ui->tableWidget_1->item(hash_key, 0)->setBackgroundColor(QColor(255, 255, 0));

            ui->tableWidget_1->setItem(hash_key, 1, new QTableWidgetItem(value_text));
            ui->tableWidget_1->item(hash_key, 1)->setBackgroundColor(QColor(255, 255, 0));
        }
    }
}

void MainWindow::printRightTable()
{
    auto table_array = rightTable.getHashTableArray();
    //clear
    ui->tableWidget_2->setRowCount(0);
    ui->tableWidget_2->setRowCount(100);
    for(int i = 0; i < TABLES_SIZE; ++i){
        if(!table_array[i].empty()){
            size_t hash_key = rightTable.hash(table_array[i].top().first);
            qDebug() << table_array[i].top().first << table_array[i].top().second;
            ui->tableWidget_2->setItem(hash_key, 0, new QTableWidgetItem(QString::number(table_array[i].top().first)));
            ui->tableWidget_2->item(hash_key, 0)->setBackgroundColor(QColor(255, 255, 0));
            ui->tableWidget_2->setItem(hash_key, 1, new QTableWidgetItem(QString::number(table_array[i].top().second)));
            ui->tableWidget_2->item(hash_key, 1)->setBackgroundColor(QColor(255, 255, 0));
        }
    }
}

