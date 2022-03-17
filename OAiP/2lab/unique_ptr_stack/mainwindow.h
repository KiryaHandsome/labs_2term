#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stack.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void pushButton_clicked();

    void popButton_clicked();

    void showHeadButton_clicked();

    void isEmptyButton_clicked();

    void getAmountButton_clicked();

    void showFullStackButton_clicked();

private:
    void writeBookInList(const Book& book);

private:
    Ui::MainWindow *ui;
    BookStack stack;

};

bool containsDigit(const QString& string);

#endif // MAINWINDOW_H
