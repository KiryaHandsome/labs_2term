#include "dialogwindow.h"
#include "ui_dialogwindow.h"
#include <QMessageBox>

DialogWindow::DialogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogWindow)
{
    ui->setupUi(this);

    ui->dateEdit->setMaxLength(10);
    ui->townCodeEdit->setMaxLength(9);
    ui->townNameEdit->setMaxLength(30);
    ui->timeEdit->setMaxLength(9);
    ui->tariffEdit->setMaxLength(9);
    ui->numberEdit->setMaxLength(9);
    ui->positionEdit->setMaxLength(4);

    connect(ui->enterButton, SIGNAL(clicked()), this, SLOT(enterButton_clicked()));
}

DialogWindow::~DialogWindow()
{
    delete ui;
}

void DialogWindow::setSizeOfList(int size)
{
    sizeOfList = size;
}

void DialogWindow::setLabelText(QString string)
{
    ui->positionLabel->setText(string);
}

void DialogWindow::enterButton_clicked()
{
    QString date = ui->dateEdit->text();
    QString townCode = ui->townCodeEdit->text();
    QString townName = ui->townNameEdit->text();
    QString time = ui->timeEdit->text();
    QString number = ui->numberEdit->text();
    QString tariff = ui->tariffEdit->text();


    QString position =ui->positionEdit->text();

    QString res = date +  '|' + townCode + '|' + townName + '|' + time + '|' + tariff + '|' + number;
    //Call(Date date, int code, QString town, int duration, QString tariff, QString number)

    if(Call().isCorrectCall(res) && (position.toInt() > 0 && position.toInt() <= sizeOfList + 1
                                     && townName != "" && tariff != "")){
        ui->dateEdit->clear();
        ui->townCodeEdit->clear();
        ui->townNameEdit->clear();
        ui->timeEdit->clear();
        ui->numberEdit->clear();
        ui->tariffEdit->clear();
        ui->positionEdit->clear();
        Date date_;
        date_.readDate(date);

        if(ui->positionLabel->text() == "Position") emit addCall(Call(date_, townCode.toInt(), townName, time.toInt(), tariff, number), position.toInt());
        else emit changeCall(Call(date_, townCode.toInt(), townName, time.toInt(), tariff, number), position.toInt());
    }
    else {
        if(position.toInt() <= 0 && position.toInt() >= sizeOfList + 1){
            QMessageBox::warning(this, "Error", "Incorrect position.");
        }
        else if(!Date().isCorrect(date)){
            QMessageBox::warning(this, "Error", "Incorrect date.\n(Date format - dd.mm.yyyy)");
        }
        else {
            QMessageBox::warning(this, "Error", "Incorrect input. Pay attention");
        }
    }

}
