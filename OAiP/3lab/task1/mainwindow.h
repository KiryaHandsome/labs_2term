#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <List.h>
#include <dialog.h>
#include <entrance.h>

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

    void readListFromFile(const QString& fileName);

    bool writeListInFile(const QString&);


private slots:
    void sortByYearButton_clicked();

    void addBookButton_clicked();

    void deleteBookEdit_returnPressed();

    void searchByNumberEdit_textChanged(QString);

    void searchByAuthorSurEdit_textChanged(QString);

    void defaulInput();

    void fileInput();

    void openNewFileAction_triggered();

    void changeBookButton_clicked();

    void addBook_called(Book book, int pos);

    void changeBook_called(Book,int);

    void updateListInFileButton_clicked();
private:
    Ui::MainWindow *ui;
    List<Book> list;
    Dialog* window;
    Entrance* entry;

    QString m_fileName = "defaultFile.txt";

};
#endif // MAINWINDOW_H
