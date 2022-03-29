#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->addRowButton, SIGNAL(clicked()), this, SLOT(addRowButton_clicked()));
    connect(ui->calculateButton, SIGNAL(clicked()), this, SLOT(calculateButton_clicked()));

    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Инф. форма"
                                                             << "Постф. форма"
                                                             << "a"
                                                             << "b"
                                                             << "c"
                                                             << "d"
                                                             << "e"
                                                             << "Ответ");
    //ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    //ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    defaultInput();
}

void MainWindow::defaultInput()
{
    const int size = 15;
    double arrA[] = { 8.6, 7.4, 3.1, 1.2, 9.7, 0.8, 1.6, 8.5, 5.6, 0.4, 5.6, 0.3, 7.6, 0.5, 9.1 };
    double arrB[] = { 2.4, 3.6, 5.4, 0.7, 8.2, 4.1, 4.9, 0.3, 7.4, 2.3, 3.2, 6.7, 4.8, 6.1, 0.6 };
    double arrC[] = { 5.1, 2.8, 0.2, 9.3, 3.6, 7.9, 5.7, 2.4, 8.9, 6.7, 0.9, 8.4, 3.5, 8.9, 2.4 };
    double arrD[] = { 0.3, 9.5, 9.6, 6.5, 4.1, 6.2, 0.8, 7.9, 3.1, 5.8, 1.7, 9.5, 9.1, 2.4, 3.7 };
    double arrE[] = { 7.9, 0.9, 7.8, 8.4, 0.5, 3.5, 2.3, 1.6, 0.2, 9.1, 4.8, 1.2, 0.2, 7.3, 8.5 };

    QString arrExprs[] = { "a/(b-c)*(d+e)", "(a+b)*(c-d)/e", "a-(b+c*d)/e", "a/b-((c+d)*e)", "a*(b-c+d)/e", "(a+b)*(c-d)/e", "a*(b-c)/(d+e)", "a/(b*(c+d))-e",
                           "(a+(b/c-d))*e", "a*(b+c)/(d-e)", "a-(b/c*(d+e))", "(a-b)/(c+d)*e", "a/(b+c-d*e)", "a*(b-c)/(d+e)", "(a+b*c)/(d-e)" };


    for(int i = 0; i < size; ++i){
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(arrExprs[i]));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(arrA[i])));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(arrB[i])));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(arrC[i])));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(arrD[i])));
        ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::number(arrE[i])));
    }
    //ui->tableWidget->item(1, 1)->setSelected(true);
}

void MainWindow::calculateButton_clicked()
{
    int size = ui->tableWidget->rowCount();

    QString expr;
    for(int i = 0; i < size; ++i){

        expr = (ui->tableWidget->item(i, 0) ? ui->tableWidget->item(i, 0)->text() : "ERROR");
        if(!RPN::isCorrectExpression(expr.toStdString()) || expr == "ERROR" ||
                (checkBrackets(expr.toStdString()).column != 0 && checkBrackets(expr.toStdString()).column != 0)){
            ui->tableWidget->setItem(i, 7, new QTableWidgetItem("INCORRECT EXPRESSION"));
        } else {
            QString rpn = QString::fromStdString(RPN::RPNconvert(expr.toStdString()));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(RPN::RPNconvert(rpn.toStdString()))));
            vector<std::string> v;
            for(int j = 2; j <= 6; ++j){
                if(ui->tableWidget->item(i, j) == 0 || (ui->tableWidget->item(i, j)->text().toDouble() == 0 && ui->tableWidget->item(i, j)->text() != "0")) v.push_back("empty");
                else v.push_back(ui->tableWidget->item(i, j)->text().toStdString());
            }
            std::string res = RPN::calculateRPN(rpn.toStdString(), v);
            if(res != "ERROR") ui->tableWidget->setItem(i, 7, new QTableWidgetItem(QString::fromStdString(res)));
            else ui->tableWidget->setItem(i, 7, new QTableWidgetItem("INCORRECT NUMBERS"));
        }
        ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    }
}

void MainWindow::addRowButton_clicked()
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}


MainWindow::~MainWindow()
{
    delete ui;
}

