#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->push_back_Button, SIGNAL(clicked()), this, SLOT(push_back_Button_clicked()));
    connect(ui->push_front_Button, SIGNAL(clicked()), this, SLOT(push_front_Button_clicked()));
    connect(ui->pop_back_Button, SIGNAL(clicked()), this, SLOT(pop_back_Button_clicked()));
    connect(ui->pop_front_Button, SIGNAL(clicked()), this, SLOT(pop_front_Button_clicked()));
    connect(ui->clear_Button, SIGNAL(clicked()), this, SLOT(clear_Button_clicked()));
    connect(ui->resize_Button, SIGNAL(clicked()), this, SLOT(resize_Button_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::print_deque()
{
    QString text;
    for(auto& it : deque){
        text += + "\"" + it + "\"" + " ";
    }
    ui->textBrowser->setText(text);
}

void MainWindow::push_back_Button_clicked()
{
    QString value = ui->inputEdit->text();

    if(value != ""){
        deque.push_back(value);
        print_deque();
    }
    else {
        QMessageBox::information(this, "Oops", "Input line is empty");
    }
}

void MainWindow::push_front_Button_clicked()
{
    QString value = ui->inputEdit->text();

    if(value != ""){
        deque.push_front(value);
        print_deque();
    }
    else {
        QMessageBox::information(this, "Oops", "Input line is empty");
    }
}

void MainWindow::pop_back_Button_clicked()
{
    if(!deque.empty()){
        deque.pop_back();
        print_deque();
    }
    else {
        QMessageBox::information(this, "Oops", "Deque is empty");
    }
}

void MainWindow::pop_front_Button_clicked()
{
    if(!deque.empty()){
        deque.pop_front();
        print_deque();
    }
    else {
        QMessageBox::information(this, "Oops", "Deque is empty");
    }
}

void MainWindow::clear_Button_clicked()
{
    if(!deque.empty()){
        deque.clear();
        print_deque();
        QMessageBox::information(this, "Succes", "Deque is clear");
    }
    else {
        QMessageBox::information(this, "Oops", "Deque is empty");
    }


}

void MainWindow::resize_Button_clicked()
{
    QString value = ui->value_Edit->text();
    QString count = ui->count_Edit->text();
    if(count.toInt() >= 0){
        deque.resize(count.toInt(), value);
        print_deque();
    }
    else {
        QMessageBox::information(this, "Oops", "Incorrect count");
    }
}

