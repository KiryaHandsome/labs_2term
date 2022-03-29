#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rpn.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void defaultInput();



private slots:
    void calculateButton_clicked();
    void addRowButton_clicked();

public:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
