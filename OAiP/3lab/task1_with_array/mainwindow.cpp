#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->updateListInFileButton, SIGNAL(clicked()), this, SLOT(updateListInFileButton_clicked()));
    connect(ui->addFieldButton, SIGNAL(clicked()), this, SLOT(addFieldButton_clicked()));
    connect(ui->changeCallButton, SIGNAL(clicked()), this, SLOT(changeCallButton_clicked()));
    connect(ui->openNewFileAction, SIGNAL(triggered()), this, SLOT(openNewFileAction_triggered()));
    connect(ui->sortByCodeButton, SIGNAL(clicked()), this, SLOT(sortByCodeButton_clicked()));
    connect(ui->searchByPhoneNumEdit, SIGNAL(textChanged(QString)), this, SLOT(searchByPhoneNumEdit_textChanged(QString)));
    connect(ui->searchByCityNameEdit, SIGNAL(textChanged(QString)), this, SLOT(searchByCityNameEdit_textChanged(QString)));
    connect(ui->deleteFieldEdit, SIGNAL(returnPressed()), this, SLOT(deleteFieldEdit_returnPressed()));

    fileName = "defaultFile.txt";
    ui->fileNameLabel->setText(fileName);

    window = new DialogWindow;
    connect(window, SIGNAL(addCall(Call,int)), this, SLOT(addCallSignal_triggered(Call,int)));
    connect(window, SIGNAL(changeCall(Call,int)), this, SLOT(changeCallSignal_triggered(Call,int)));

    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);

    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Date"
                                                             << "Town code"
                                                             << "Town"
                                                             << "Duration"
                                                             << "Tariff"
                                                             << "Number");
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


}

MainWindow::~MainWindow()
{
    delete window;
    delete ui;
}




void MainWindow::updateListInFileButton_clicked()
{
    if(list.size() != 0){
        writeListInFile(fileName);
    } else{
        QMessageBox::warning(this, "Error", "List is empty.");
    }
}


void MainWindow::addFieldButton_clicked()
{
    this->hide();
    window->setSizeOfList(list.size());
    window->show();
}


void MainWindow::changeCallButton_clicked()
{
    if(list.size() != 0){
        window->show();
        this->hide();
        window->setSizeOfList(list.size());
        window->setLabelText("Pos to change");
    } else {
        QMessageBox::warning(this, "Error", "List is empty. Nothing to change.");
    }

}

void MainWindow::addCallSignal_triggered(Call call, int position)
{
    window->hide();
    this->show();
    list.insert(call, position - 1);
    //list.push_back(call);
    printListInTable();
}

void MainWindow::changeCallSignal_triggered(Call call, int position)
{
    window->hide();
    this->show();
    list.erase(position - 1);
    list.insert(call, position - 1);
    printListInTable();
}

void MainWindow::printListInTable()
{
    ui->tableWidget->clear();   //clear table
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);

    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Date"
                                                             << "Town code"
                                                             << "Town"
                                                             << "Duration"
                                                             << "Tariff"
                                                             << "Number");

    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);

    int counter = 0;
    if(list.size() != 0) {
        for(auto it = list.begin(); it != list.end(); ++it){
            ui->tableWidget->insertRow(counter);
            ui->tableWidget->setItem(counter, 0, new QTableWidgetItem((*it).date.showDate())); //add data to table
            ui->tableWidget->setItem(counter, 1, new QTableWidgetItem(QString::number((*it).code)));
            ui->tableWidget->setItem(counter, 2, new QTableWidgetItem((*it).town));
            ui->tableWidget->setItem(counter, 3, new QTableWidgetItem(QString::number((*it).duration)));
            ui->tableWidget->setItem(counter, 4, new QTableWidgetItem((*it).tariff));
            ui->tableWidget->setItem(counter, 5, new QTableWidgetItem((*it).number));
            counter++;
        }
    } else {
        QMessageBox::warning(this, "Error", "List is empty");
    }

}

void MainWindow::writeListInFile(const QString& name)
{
    QFile file(name);
    if(file.open(QIODevice::ReadWrite)){
       QTextStream stream(&file);

       for(auto it = list.begin(); it != list.end(); ++it){

           QString out = (*it).date.showDate() + "|" + QString::number((*it).code) + "|" + (*it).town
                   +  "|" + QString::number((*it).duration) + "|" + (*it).tariff + "|" +  (*it).number + "\n";
           stream << out;
           stream.flush();
       }
       QMessageBox::information(this, "File updating", "File was updated successfully. Check it.");
    } else {
        QMessageBox::warning(this, "Error", "File not opened.");
    }
}

void MainWindow::openNewFileAction_triggered()
{
    QString name = QFileDialog::getOpenFileName(this, "Choose file", "C:\\", "*.txt");

    readListFromFile(name);
}

void MainWindow::sortByCodeButton_clicked()
{
    if(list.size() != 0){
        quickSort(list.getArr(), 0, list.size() - 1);
        printListInTable();
    } else{
        QMessageBox::warning(this, "Error","List is empty.");
    }
}

void MainWindow::searchByPhoneNumEdit_textChanged(QString text)
{
    if(list.size() != 0){
        for(int i = 0; i < ui->tableWidget->rowCount(); i++){
            for(int j = 0; j < ui->tableWidget->columnCount(); j++){
                ui->tableWidget->item(i, j)->setBackground(QBrush(Qt::white));  //clear table
            }
        }
        int counter = 0;
        for(auto it = list.begin(); it != list.end(); ++it){
            if((*it).number.contains(text) && text != ""){
                for(int j = 0; j < 6; j++) ui->tableWidget->item(counter, j)->setBackground(QBrush(Qt::yellow));
            }
            counter++;
        }
    } else {
        if(text != "") QMessageBox::warning(this, "Error","List is empty.");
    }
}

void MainWindow::searchByCityNameEdit_textChanged(QString text)
{
    if(list.size() != 0){
        for(int i = 0; i < ui->tableWidget->rowCount(); i++){
            for(int j = 0; j < ui->tableWidget->columnCount(); j++){
                ui->tableWidget->item(i, j)->setBackground(QBrush(Qt::white));  //clear table
            }
        }
        int counter = 0;
        for(auto it = list.begin(); it != list.end(); ++it){
            if((*it).town.contains(text) && text != ""){
                for(int j = 0; j < 6; j++) ui->tableWidget->item(counter, j)->setBackground(QBrush(Qt::yellow));
            }
            counter++;
        }
    } else {
        if(text != "") QMessageBox::warning(this, "Error","List is empty.");
    }
}

void MainWindow::readListFromFile(const QString& _fileName)
{
    QFile file(_fileName);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        QString line;
        while(!stream.atEnd()){
            line = stream.readLine();
            if(line != "" && !Call().isCorrectCall(line)){
                file.close();
                QMessageBox::warning(this, "Error", "Data in file not correct!\nChoose another file.");
                return;
            }
        }
        int list_size = list.size();
        for(int i = 0; i < list_size; ++i){
            list.erase(1);      //clear old list
        }
        fileName = _fileName;
        QStringList fileList = fileName.split('/');
        ui->fileNameLabel->setText(fileList[fileList.size() - 1]);
        stream.seek(0);
        while(!stream.atEnd()){
            line = stream.readLine();
            if(line != "") list.push_back(Call().convertToCall(line));
        }
        printListInTable();

    }
    else {
        QMessageBox::warning(this, "Error", "Oops...File not opened.");
    }
}

void MainWindow::deleteFieldEdit_returnPressed()
{
    if(list.size() != 0){
        int pos = ui->deleteFieldEdit->text().toInt();
        if(pos <= 0 || pos > list.size()){
            QMessageBox::warning(this, "Error","Incorrect input.");
        } else {
            list.erase(pos - 1);
            ui->deleteFieldEdit->clear();
            printListInTable();
        }
    } else {
        QMessageBox::warning(this, "Error","List is empty.");
    }

}

