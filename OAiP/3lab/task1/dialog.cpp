#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->enterButton, SIGNAL(clicked()), this, SLOT(enterButton_clicked()));

    ui->authorEdit->setMaxLength(40);
    ui->pagesEdit->setMaxLength(9);
    ui->publisherEdit->setMaxLength(30);
    ui->titleEdit->setMaxLength(40);
    ui->positionEdit->setMaxLength(9);
    ui->yearEdit->setMaxLength(4);
    ui->regNumEdit->setMaxLength(9);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::enterButton_clicked()
{
    QString regNumber = ui->regNumEdit->text() ;
    QString author = ui->authorEdit->text();
    QString title = ui->titleEdit->text();
    QString year = ui->yearEdit->text();
    QString publisher = ui->publisherEdit->text();
    QString pages = ui->pagesEdit->text();

    QString position = ui->positionEdit->text();

    QString res = regNumber +  '|' + author + '|' + title + '|' + year + '|' + publisher + '|' + pages;

    if(Book().isCorrectBook(res) && (position.toInt() <= sizeOfList + 1  && position.toInt() > 0)){
        ui->regNumEdit->clear();
        ui->authorEdit->clear();
        ui->titleEdit->clear();
        ui->yearEdit->clear();
        ui->publisherEdit->clear();
        ui->pagesEdit->clear();
        ui->positionEdit->clear();
        if(ui->positionLabel->text() == "Position") emit addBook(Book(regNumber.toInt(), author, title, year.toInt(), publisher, pages.toInt()), position.toInt());
        else emit changeBook(Book(regNumber.toInt(), author, title, year.toInt(), publisher, pages.toInt()), position.toInt());
    }
    else {
        QMessageBox::warning(this, "Error", "Incorrect input.\nPay attention.");
    }
}

void Dialog::setSizeOfList(int size) { sizeOfList = size; }

void Dialog::setLabelText(QString string)
{
    ui->positionLabel->setText(string);
}
