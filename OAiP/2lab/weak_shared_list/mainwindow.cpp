#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMessageBox::information(this, "Introducing", "weak_ptr is a smart pointer that holds a non-owning (weak) reference"
                                                  " to an object that is managed by shared_ptr. It must be converted to shared_ptr in order to access the referenced object.");
    connect(ui->insertButton, SIGNAL(clicked()), this, SLOT(insertButton_clicked()));
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(deleteButton_clicked()));
    connect(ui->printInFileButton, SIGNAL(clicked()), this, SLOT(printInFileButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::insertButton_clicked()
{
    QString num = ui->numberEdit->text();
    QString pos = ui->positionEdit->text();

    if(num == ""){
        QMessageBox::warning(this, "Error", "Empty input");
        return;
    }else if((num.toInt() == 0 && num != "0" ) || pos.toInt() < 1 || pos.toInt() - 1 > ui->listWidget->count()){
        QMessageBox::warning(this, "Error", "Incorrect input");
        return;
    } else {
        int position = pos.toInt() - 1;
        list.insert(num.toInt(), position);
        ui->listWidget->insertItem(position, new QListWidgetItem(num));
        ui->numberEdit->clear();
        ui->positionEdit->clear();
    }
}

void MainWindow::deleteButton_clicked()
{
    int indx = ui->positionEdit_2->text().toInt();

    if(indx < 1 || indx > ui->listWidget->count()){
        QMessageBox::warning(this, "Error", "Incorrect input");
    }else {
        list.erase(indx - 1);
        ui->listWidget->removeItemWidget(ui->listWidget->item(indx - 1));
        delete ui->listWidget->item(indx - 1);
        ui->listWidget->update();
        ui->positionEdit_2->clear();
    }
}

void MainWindow::printInFileButton_clicked()
{
    if(!list.printListInFile()){
        QMessageBox::warning(this, "Error", "File not opened");
    }

}
