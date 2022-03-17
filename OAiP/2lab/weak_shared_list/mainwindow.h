#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "doubly_linked_list.h"

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
    void insertButton_clicked();
    void deleteButton_clicked();
    void printInFileButton_clicked();


private:
    DoublyLinkedList list;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
