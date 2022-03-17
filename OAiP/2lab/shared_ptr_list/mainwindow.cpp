#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QMessageBox::information(this, "Introducing", "shared_ptr is a smart pointer that retains shared ownership of an object through a pointer.\n"
                                                  "Several shared_ptr objects may own the same object. This program demonstrate list which based on shared_ptr");
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(pushButton_clicked()));
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(deleteButton_clicked()));
    connect(ui->printInFileButton, SIGNAL(clicked()), this, SLOT(printInFileButton_clicked()));

    ui->pushEdit->setPlaceholderText("Enter string...");
    ui->deleteEdit->setPlaceholderText("Enter index...");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pushButton_clicked()
{
    std::string str = ui->pushEdit->text().toStdString();

    if(str == ""){
        QMessageBox::warning(this, "Error", "Empty string");
        return;
    }

    ui->listWidget->addItem(QString::fromStdString(str));
    strList.push_back(str);
    ui->pushEdit->clear();
}

void MainWindow::deleteButton_clicked()
{
    int indx = ui->deleteEdit->text().toInt();

    if(indx < 1 || indx > ui->listWidget->count()){
        QMessageBox::warning(this, "Error", "Incorrect input");
    }else {
        strList.deleteNode(indx);
        ui->listWidget->removeItemWidget(ui->listWidget->item(indx - 1));
        delete ui->listWidget->item(indx - 1);
        ui->listWidget->update();
        ui->deleteEdit->clear();
    }
}

void MainWindow::printInFileButton_clicked()
{
    strList.printInFile(this);
}

