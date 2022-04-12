#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <thread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->getResultButton, SIGNAL(clicked()), this, SLOT(getResultButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getResultButton_clicked()
{
    int number = ui->lineEdit->text().toInt();

    if(number < 1 || number > 10000){
        QMessageBox::information(this, "Oops", "Incorrect input.");
        return;
    }

    QString bindec_number = QString::fromStdString(bindecimalNumber(number));
    ui->textBrowser->setText(bindec_number);

}

bool MainWindow::k_bit(string str, int k)
{
    int bit, i = 0;
    int lenstr = str.size();

    for (; i != k; i++)
    {
        bit = (str[lenstr - 1] - '0') % 2;
        str[lenstr - 1] = str[lenstr - 1] - bit;

        for (int j = lenstr - 1; j >= 0; j--)
        {
            if ((str[j] - '0') % 2 == 0)
            {
                str[j] = (str[j] - '0') / 2 + '0';
            }
            else
            {
                str[j] = (str[j] - '0') / 2 + '0';

                if (j != lenstr - 1)
                {
                    str[j + 1] = str[j + 1] + 5;
                }

            }
        }
    }

    return (bool)bit;
}

string MainWindow::powstr(const string& str, int k)
{
    string deg = "1";

    if (k == 0)
    {
        return("1");
    }

    for (int i = 0; i < k; i++)
    {
        deg += '0';
    }

    for (int i = deg.size() - 1, j = str.size() - 1; i >= 0 && j >= 0; i--, j--)
    {
        deg[i] = str[j];
    }

    return(deg);
}

string MainWindow::bindecimalNumber(int number)
{
    string* A = new string[10000];
    string* B = new string[10000];

    A[0] = "0";

    int counterB, counterA = 1, k = 1, counterBIN = 1, tmp;


    while (number >= counterBIN)
    {
        tmp = counterB = 0;

        for (int i = 0; i < counterA; i++)
        {
            if (!k_bit(A[i], k))
            {
                A[tmp] = A[i];
                tmp++;
            }
        }

        counterA = tmp;

        for (int i = 0; i < counterA; i++)
        {
            B[i] = powstr(A[i], k - 1);
            counterB++;
        }

        for (int i = 0; i < counterB; i++)
        {
            A[counterA] = B[i];
            counterA++;
        }

        counterBIN += counterB;
        k++;
    }

    string result = B[counterB - (counterBIN - number)];

    delete[] A;
    delete[] B;
    return result;
}

