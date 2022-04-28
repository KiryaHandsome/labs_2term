#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "HashTable.h"

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
    void createTable();

    void AddToTable();

    void RemoveFromTable();

    void SearchInTable();

    void Create2Tables();

    void printLeftTable();

    void printRightTable();

private:
    Ui::MainWindow *ui;
    HashTable leftTable;
    HashTable rightTable;
};
#endif // MAINWINDOW_H
