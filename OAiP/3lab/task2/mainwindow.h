#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Balanced.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void checkText(const std::string& input);

private slots:
    void chooseFileButton_clicked();

    void checkTextButton_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
