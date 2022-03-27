#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <fstream>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->chooseFileButton, SIGNAL(clicked()), this, SLOT(chooseFileButton_clicked()));
    connect(ui->checkTextButton, SIGNAL(clicked()), this, SLOT(checkTextButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::chooseFileButton_clicked()
{
    QString name = QFileDialog::getOpenFileName(this, "Выберите файл", "D:\\");

    QFile file(name);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        QString string = stream.readAll();
        ui->textEdit->setText(string);
        std::string input = string.toStdString();
        checkText(input);
    } else {
        QMessageBox::warning(this, "Error", "Oops...File not opened.");
    }
}


void MainWindow::checkTextButton_clicked()
{
    std::string input = ui->textEdit->toPlainText().toStdString();
    checkText(input);
}

void MainWindow::checkText(const std::string& input)
{
    Position pos = checkBrackets(input);
    if (pos.row == 0 && pos.column == 0){
        QMessageBox::information(this, "Успешно", "Скобки расставлены корректно.");
    }
    else {
        QString row = QString::number(pos.row);
        QString col = QString::number(pos.column);
        QString text = "Скобки расставлены некорректно\n(строка " + row + " столбец " + col + " )";
        QMessageBox::information(this, "Уупс", text);
    }
}

