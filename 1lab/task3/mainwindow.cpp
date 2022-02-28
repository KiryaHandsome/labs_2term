#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    this->createUI(QStringList() << ("Date")
                                 << ("Next day")
                                 << ("is Leap")
                                 << ("Previous day")
                                 << ("Duration")
                                 << ("Week number"));

    connect(ui->isLeapButton, SIGNAL(clicked()), this, SLOT(isLeapButton_clicked()));
    connect(ui->weekNumberButton, SIGNAL(clicked()), this, SLOT(weekNumberButton_clicked()));
    connect(ui->nextDayButton, SIGNAL(clicked()), this, SLOT(nextDayButton_clicked()));
    connect(ui->previousDayButton, SIGNAL(clicked()), this, SLOT(previousDayButton_clicked()));
    connect(ui->daysTillBDButton, SIGNAL(clicked()), this, SLOT(daysTillBDButton_clicked()));
    connect(ui->durationButton, SIGNAL(clicked()), this, SLOT(durationButton_clicked()));
    connect(ui->changeDateButton, SIGNAL(clicked()), this, SLOT(changeDateButton_clicked()));
    connect(ui->addDateButton, SIGNAL(clicked()), this, SLOT(addDateButton_clicked()));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(actionOpen_triggered()));

    QString tmp;
    for(int i = 1 ; i <= ui->tableWidget->rowCount(); i++){
        tmp = QString::number(i);
        ui->comboBox->addItem(tmp);
    }

    window.setComboBox(&(*ui->comboBox));
    window.setTableWidget(&(*ui->tableWidget));


}

MainWindow::~MainWindow()
{
    delete [] info;
    delete ui;
}


int MainWindow::createUI(const QStringList &headers, QString file_name)
{
    ui->tableWidget->clear();   //clear table
    ui->tableWidget->setRowCount(0);

    ui->tableWidget->setHorizontalHeaderLabels(headers);

    ui->tableWidget->setColumnCount(6);

    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QFile file(file_name);
    int count = 0;
    if(file.open(QIODevice::ReadWrite)){
        QTextStream stream(&file);

        QString line; //temporary string

        while(!stream.atEnd()) {
            stream >> line;
            if(line == ""){

            }
            else if(!Date().isCorrect(line)){
                file.close();
                QMessageBox::warning(this, "Error", "Data in file not correct!\nChoose another file.");
                return -1;
            }
            else ++count; //count dates in file
        }
        if(info) delete [] info;
        info = new Date[count]; //allocate memory to input data from file

        stream.seek(0);   //set pointer at the beginning
        for(int i = 0; i < count; i++) {
            stream >> line;         //read data from file
            info[i].readDate(line); //iterate in array
        }
        file.close();
        for(int i = 0; i < count; i++){
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(info[i].showDate())); //add dates to table
        }
        ui->tableWidget->resizeColumnsToContents();
    }
    return 0;
}

void MainWindow::nextDayButton_clicked()
{
    QString str = ui->comboBox->currentText();
    int row = str.toInt() - 1;
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(info[row].nextDay().showDate())); //show next day
}

void MainWindow::previousDayButton_clicked()
{
    QString str = ui->comboBox->currentText();
    int row = str.toInt() - 1;
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(info[row].previousDay().showDate())); //show previous day
}

void MainWindow::daysTillBDButton_clicked()
{
    window.setLabelText("Enter date of Your birthday");
    window.show();
}

void MainWindow::isLeapButton_clicked()
{
    QString str = ui->comboBox->currentText();
    int row = str.toInt() - 1;
    QString var = (info[row].isLeap() ? "True" : "False");

    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(var));
}

void MainWindow::weekNumberButton_clicked()
{
    QString str = ui->comboBox->currentText();
    int row = str.toInt() - 1;
    ui->tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(info[row].weekNumber()))); //week number
}

void MainWindow::durationButton_clicked()
{
    QString str = ui->comboBox->currentText();
    int row = str.toInt() - 1;
    int nextRow = (row + 1) % ui->tableWidget->rowCount();
    ui->tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(info[row].duration(info[nextRow]))));
    window.hide();
}

void MainWindow::changeDateButton_clicked()
{
    window.setFileName(fileName);
    window.show();
    window.raise();
    window.setLabelText("Enter your date");
    window.setCurrentRow(ui->comboBox->currentText().toInt());

}

void MainWindow::addDateButton_clicked()
{
    window.setFileName(fileName);
    window.show();
    window.raise();
    window.setLabelText("Enter new date");
    window.setCurrentRow(ui->comboBox->currentText().toInt());
}


void MainWindow::actionOpen_triggered()
{
    QString name = QFileDialog::getOpenFileName(this, "Choose file", "C:\\", "*.txt");

    if(QFile(name).open(QIODevice::ReadWrite)){



        int res = this->createUI(QStringList()   << ("Date")
                                                 << ("Next day")
                                                 << ("is Leap")
                                                 << ("Previous day")
                                                 << ("Duration")
                                                 << ("Week number"), name);
        if(res == 0){
            fileName = name;
            window.setFileName(fileName);
            ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            ui->comboBox->clear();
            QString tmp;
            for(int i = 1 ; i <= ui->tableWidget->rowCount(); i++){
                tmp = QString::number(i);
                ui->comboBox->addItem(tmp);
            }
        }

    }
}

