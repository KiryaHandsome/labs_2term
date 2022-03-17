#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMessageBox::information(this, "Introducing", "unique_ptr is a smart pointer that owns and manages another object through"
                                                  " a pointer and disposes of that object when the unique_ptr goes out of scope.\n"
                                                  "This program use stack based on unique_ptr");

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(pushButton_clicked()));
    connect(ui->showHeadButton, SIGNAL(clicked()), this, SLOT(showHeadButton_clicked()));
    connect(ui->popButton, SIGNAL(clicked()), this, SLOT(popButton_clicked()));
    connect(ui->isEmptyButton, SIGNAL(clicked()), this, SLOT(isEmptyButton_clicked()));
    connect(ui->getAmountButton, SIGNAL(clicked()), this, SLOT(getAmountButton_clicked()));

    ui->bookCodeEdit->setMaxLength(4);
    ui->yearEdit->setMaxLength(4);
    ui->authorSurnameEdit->setMaxLength(15);
    ui->titleEdit->setMaxLength(30);

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool containsDigit(const QString& string)
{
    for(int i = 0; i < string.size(); i++){
        if(string[i].isDigit()) return true;
    }
    return false;
}

void MainWindow::pushButton_clicked()
{
    int code = ui->bookCodeEdit->text().toInt();
    QString surname = ui->authorSurnameEdit->text();
    QString title = ui->titleEdit->text();
    int year = ui->yearEdit->text().toInt();

    if(code == 0 || year == 0 || year > 2022 || containsDigit(surname) || year < 0){
        QMessageBox::warning(this, "Error", "Incorrect input.\nPay attention.");
        return;
    }

    Book answ(code, surname.toStdString(), title.toStdString(), year);

    stack.push(answ);

    writeBookInList(answ);

    ui->bookCodeEdit->setText("");
    ui->authorSurnameEdit->setText("");
    ui->yearEdit->setText("");
    ui->titleEdit->setText("");
}

void MainWindow::writeBookInList(const Book& book)
{
    ui->listWidget->clear();
    ui->listWidget->addItem(QString::number(book.getBookCode()));
    ui->listWidget->addItem(QString::fromStdString(book.getTitle()));
    ui->listWidget->addItem(QString::fromStdString(book.getAuthorSurname()));
    ui->listWidget->addItem(QString::number(book.getYear()));
}

void MainWindow::popButton_clicked()
{
    if(stack.isEmpty()){
        QMessageBox::warning(this, "Error", "Stack is empty");
        ui->listWidget->clear();
    }
    else {
        writeBookInList(stack.pop(this));

    }
}

void MainWindow::showHeadButton_clicked()
{
    if(stack.isEmpty()){
        QMessageBox::warning(this, "Error", "Stack is empty");
    }
    else {
        writeBookInList(stack.Head(this));
    }
}

void MainWindow::isEmptyButton_clicked()
{
    QString answ = (stack.isEmpty() ? "YES" : "NO");

    ui->statusbar->showMessage(answ);
}

void MainWindow::getAmountButton_clicked()
{
    ui->statusbar->showMessage(QString::number(stack.getAmount()));
}
