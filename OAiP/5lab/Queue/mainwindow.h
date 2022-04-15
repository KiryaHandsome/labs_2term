#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "queue.h"
#include "c_list.h"

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

    void frontButton_clicked();

    void backButton_clicked();

    void isEmptyButton_clicked();

    void sizeButton_clicked();

    void leftButton_clicked();

    void rightButton_clicked();

private:
    Ui::MainWindow *ui;
    Queue<QString> queue;
    List<QString> list;
    List<QString>::iterator iterator;
    bool listIsCorrect;
};
#endif // MAINWINDOW_H
