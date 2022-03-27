#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "list.h"
#include "dialogwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void printListInTable();

    void writeListInFile(const QString& name);

    void readListFromFile(const QString& fileName);

private slots:

    void updateListInFileButton_clicked();

    void addFieldButton_clicked();

    void changeCallButton_clicked();

    void addCallSignal_triggered(Call, int);

    void changeCallSignal_triggered(Call, int);

    void openNewFileAction_triggered();

    void sortByCodeButton_clicked();

    void searchByPhoneNumEdit_textChanged(QString);

    void searchByCityNameEdit_textChanged(QString);

    void deleteFieldEdit_returnPressed();
private:
    Ui::MainWindow *ui;
    List<Call> list;
    QString fileName;
    DialogWindow* window;

};
#endif // MAINWINDOW_H
