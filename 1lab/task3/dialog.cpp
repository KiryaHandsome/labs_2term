#include "dialog.h"
#include "ui_dialog.h"
#include "date.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

Date* info; //global var for dialog.cpp and mainwindow.cpp


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->enterButton, SIGNAL(clicked()), this, SLOT(enterButton_clicked()));

}

Dialog::~Dialog()
{

    delete ui;
}

void Dialog::enterButton_clicked()
{

    QString day = ui->dayEdit->text();
    QString month = ui->monthEdit->text();
    QString year = ui->yearEdit->text();

    Date tmp(day.toInt(), month.toInt(), year.toInt());

    if(tmp.isCorrect(day + '.' + month + '.' + year)){
        this->hide();

        if(ui->mainLabel->text() == "Enter date of Your birthday"){
            QMessageBox::information(this, "Days till birthday ",
                                     QString::number(info[row].daysTillYourBirthday(tmp))
                                     + " till Your birthday!!!");
        }
        else if(ui->mainLabel->text() == "Enter your date"){  //if button "change current day" was clicked

            for(int i = 0; i < 6; i++) widget->setItem(row, i, new QTableWidgetItem); //clear fields

            widget->setItem(row, 0, new QTableWidgetItem(tmp.showDate()));
            info[row] = tmp;    //change date in array

            QFile file(fileName);
            if(file.open(QIODevice::ReadWrite)){
                file.seek(row * 11); //set need position

                QTextStream stream(&file);
                QString string = tmp.showDate();

                string += ' '; //rewrite current date in file

                stream << string;   //change date in file
                file.close();
            }
        }
        else {  //button "add new date" was clicked

            Date* buffer = new Date[widget->rowCount()];
            for(int i = 0; i < widget->rowCount(); i++){
                buffer[i] = info[i];       //copy informaytion
                qDebug() << buffer[i].showDate();
            }
            delete [] info;
            info = new Date[widget->rowCount() + 1];   //reallocate memory for new date
            for(int i = 0; i < widget->rowCount(); i++){
                info[i] = buffer[i];

            }
            delete [] buffer;

            info[widget->rowCount()] = tmp;

            widget->insertRow(widget->rowCount()); //add new row

            widget->setItem(widget->rowCount() - 1, 0, new QTableWidgetItem(info[widget->rowCount() - 1].showDate()));

            QFile file(fileName);
            if(file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)){

                QTextStream stream(&file);
                QString string = info[widget->rowCount() - 1].showDate() + ' ';

                stream << string;   //add date to end of file

                file.close();
            }
            box->addItem(QString::number(widget->rowCount()));

        }
    } else {
        QMessageBox::warning(this, "Error", "Invalid input!\nTry again");
    }
    ui->dayEdit->clear();
    ui->monthEdit->clear();
    ui->yearEdit->clear();
}

void Dialog::setLabelText(QString text)
{
    ui->mainLabel->setText(text);
}

void Dialog::setCurrentRow(int row) { this->row = row - 1; }

void Dialog::setTableWidget(QTableWidget* widget)
{
    this->widget = widget;
}

void Dialog::setComboBox(QComboBox* box)
{
    this->box = box;
}

void Dialog::setFileName(QString fileName)
{
    this->fileName = fileName;
}

