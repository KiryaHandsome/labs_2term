#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
using std::string;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void getResultButton_clicked();

private:
    Ui::MainWindow *ui;
    bool k_bit(string str, int k);
    string powstr(const string& str, int k);
    string bindecimalNumber(int number);
    QString bin_number;
};
#endif // MAINWINDOW_H
