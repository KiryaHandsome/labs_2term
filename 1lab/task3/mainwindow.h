#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "date.h"
#include "dialog.h"

extern Date* info;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int createUI(const QStringList &headers, QString file_name = "file.txt");

private slots:
    void nextDayButton_clicked();

    void previousDayButton_clicked();

    void daysTillBDButton_clicked();

    void isLeapButton_clicked();

    void weekNumberButton_clicked();

    void durationButton_clicked();

    void changeDateButton_clicked();

    void addDateButton_clicked();

    void actionOpen_triggered();

private:
    Dialog window;
    Ui::MainWindow *ui;
    QString fileName;
};
#endif // MAINWINDOW_H
