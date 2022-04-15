#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidget>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connects buttons with slots
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(pushButton_clicked()));
    connect(ui->popButton, SIGNAL(clicked()), this, SLOT(popButton_clicked()));
    connect(ui->frontButton, SIGNAL(clicked()), this, SLOT(frontButton_clicked()));
    connect(ui->backButton, SIGNAL(clicked()), this, SLOT(backButton_clicked()));
    connect(ui->isEmptyButton, SIGNAL(clicked()), this, SLOT(isEmptyButton_clicked()));
    connect(ui->sizeButton, SIGNAL(clicked()), this, SLOT(sizeButton_clicked()));
    connect(ui->leftButton, SIGNAL(clicked()), this, SLOT(leftButton_clicked()));
    connect(ui->rightButton, SIGNAL(clicked()), this, SLOT(rightButton_clicked()));

    //set max lenght to input line
    ui->lineEdit->setMaxLength(40);

    //add code of this program to circle list
    QFile file("E:/labs/labs2sem/5lab/task1/mainwindow.cpp");
    if(file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        while(!stream.atEnd()){
            list.push_back(stream.readLine());
        }
        //set flag listIsCorrect
        listIsCorrect = true;
        iterator = list.begin();
    } else {
        QMessageBox::warning(this, "Error", "File not opened.");
        //set flag listIsCorrect
        listIsCorrect = false;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pushButton_clicked()
{
    QString text = ui->lineEdit->text();
    if(text != ""){
        queue.push("\"" + text + "\"");
        ui->textBrowser->setText("Successful push(\"" + text + "\")");
        ui->lineEdit->clear();
    }
    else {
        ui->textBrowser->setText("Input line is empty.");
    }
}

void MainWindow::popButton_clicked()
{
    if(!queue.isEmpty()){
        queue.pop();
        ui->textBrowser->setText("Successful pop!");
    }
    else {
        ui->textBrowser->setText("Queue is empty.");
    }
}

void MainWindow::frontButton_clicked()
{
    if(!queue.isEmpty()){
        QString text = queue.front();
        ui->textBrowser->setText(text);
    }
    else {
        ui->textBrowser->setText("Queue is empty.");
    }
}

void MainWindow::backButton_clicked()
{
    if(!queue.isEmpty()){
        ui->textBrowser->setText(queue.back());
    }
    else {
        ui->textBrowser->setText("Queue is empty.");
    }

}

void MainWindow::isEmptyButton_clicked()
{
    ui->textBrowser->setText("isEmpty = " + QString((queue.isEmpty() ? "true" : "false")));
}

void MainWindow::sizeButton_clicked()
{
    ui->textBrowser->setText("Size: " + QString::number(queue.size()));
}

void MainWindow::leftButton_clicked()
{
    if(listIsCorrect){
        --iterator;
        QString line = *iterator;
        if(line == ""){
            ui->codeBrowser->setText("Empty line");
        }
        else ui->codeBrowser->setText(line);
    } else{
        ui->codeBrowser->setText("Happened something wrong...");
    }
}

void MainWindow::rightButton_clicked()
{
    if(listIsCorrect){
        ++iterator;
        QString line = *iterator;
        if(line == ""){
            ui->codeBrowser->setText("Empty line");
        }
        else ui->codeBrowser->setText(line);
    } else{
        ui->codeBrowser->setText("Happened something wrong...");
    }
}

