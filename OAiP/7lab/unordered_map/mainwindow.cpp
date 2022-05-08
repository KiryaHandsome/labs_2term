#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->insertButton, SIGNAL(clicked()), this, SLOT(insert()));
    connect(ui->findButton, SIGNAL(clicked()), this, SLOT(find()));
    connect(ui->eraseButton, SIGNAL(clicked()), this, SLOT(erase()));
    connect(ui->rehashButton, SIGNAL(clicked()), this, SLOT(rehash()));
    connect(ui->containsButton, SIGNAL(clicked()), this, SLOT(contains()));
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::insert()
{
    QString key = ui->insert_KeyEdit->text();
    QString value = ui->insert_ValueEdit->text();
    if(key.toInt() == 0 && key != "0"){
        QMessageBox::warning(this, "Warning", "Key is not correct.");
        return;
    }
    auto pair = map.insert({key.toInt(), value});
    if(pair.second){
        updateTable();
        QMessageBox::information(this, "Info", "Data added successfully.");
        ui->insert_KeyEdit->clear();
        ui->insert_ValueEdit->clear();
    }
    else {
        QMessageBox::information(this, "Info", "Value with such key already exist.");
    }
}

void MainWindow::find()
{
     QString key = ui->find_Edit->text();
     if(key.toInt() == 0 && key != "0"){
         QMessageBox::warning(this, "Warning", "Key is not correct.");
         return;
     }

     auto data = map.find(key.toInt());
     if(data != map.end()){
        QMessageBox::information(this, "Info", "Found value by key " + key + " - " + (*data).second);
        ui->find_Edit->clear();
     }
     else {
        QMessageBox::information(this, "Info", "No value with such key.");
     }
}

void MainWindow::erase()
{
    QString key = ui->erase_Edit->text();
    if(key.toInt() == 0 && key != "0"){
        QMessageBox::warning(this, "Warning", "Key is not correct.");
        return;
    }

    bool result = map.erase(key.toInt());
    if(result == 1){
        updateTable();
        QMessageBox::information(this, "Info", "Value with key " + key + " was removed");
        ui->erase_Edit->clear();
    }
    else {
        QMessageBox::information(this, "Info", "No value with such key.");
    }
}

void MainWindow::rehash()
{
    QString count = ui->rehashEdit->text();
    if(count.toInt() == 0 && count != "0"){
        QMessageBox::warning(this, "Warning", "Count is not correct.");
        return;
    }
    bool rehash = map.rehash(count.toInt());
    if(rehash){
        updateTable();
        QMessageBox::information(this, "Info", "Table was rehashed.");
    }
    else {
        QMessageBox::information(this, "Info", "Table doesn't need in rehash.");
    }

}

void MainWindow::contains()
{
    QString key = ui->containsEdit->text();
    if(key.toInt() == 0 && key != "0"){
        QMessageBox::warning(this, "Warning", "Key is not correct.");
        return;
    }

    QMessageBox::information(this, "Info", "function return " + QString(map.contains(key.toInt()) ? "true" : "false"));

}

void MainWindow::updateTable()
{
    ui->tableWidget->setRowCount(0);
    for(int i = 0; i < map.bucket_count(); ++i){
        ui->tableWidget->insertRow(i);
        if(!map.buckets[i].empty()){
            QString keys, values;
            for(auto& k : map.buckets[i]){
                keys += QString::number(k->first) + " ";
                values += k->second + " ";
            }
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(keys));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(values));
        }
    }
}

