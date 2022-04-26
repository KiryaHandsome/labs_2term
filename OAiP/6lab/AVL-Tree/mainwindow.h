#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Tree.h"
#include "visualtree.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void AddButton_clicked();
    void DeleteButton_clicked();
    void FindButton_clicked();
    void PrintButton_clicked();
    void InputButton_clicked();
    void AddCellButton_clicked();

    void ClearArrayTable();

    void updateTable();

    void drawTree();

    void NumOfNodes();




private:
    Ui::MainWindow *ui;
    MyTree tree;
    VisualTree* window;
};
#endif // MAINWINDOW_H
