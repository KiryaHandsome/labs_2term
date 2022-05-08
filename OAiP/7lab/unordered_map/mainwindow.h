#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Unordered_map.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateTable();


private slots:
    void insert();

    void find();

    void erase();

    void rehash();

    void contains();

private:
    Ui::MainWindow *ui;
    Unordered_map<int, QString> map;

};
#endif // MAINWINDOW_H
