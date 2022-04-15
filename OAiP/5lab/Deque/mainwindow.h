#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "deque.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void print_deque();

private slots:
    void push_back_Button_clicked();

    void push_front_Button_clicked();

    void pop_back_Button_clicked();

    void pop_front_Button_clicked();

    void clear_Button_clicked();

    void resize_Button_clicked();



private:
    Ui::MainWindow *ui;
    deque<QString> deque;
};
#endif // MAINWINDOW_H
