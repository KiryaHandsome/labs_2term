#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "List.h"

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

    void deleteButton_clicked();

    void printInFileButton_clicked();

private:
    Ui::MainWindow *ui;
    StringList strList;
};
#endif // MAINWINDOW_H
