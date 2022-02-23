#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "library.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void rewriteBooks();

    void rewriteReaders();

    void rewriteBooksInFile();

    void rewriteReadersInFile();

private slots:

    void booksButton_clicked();

    void readersBooksButton_clicked();

    void readersButton_clicked();

    void debtorsButton_clicked();

    void addBookButton_clicked();

    void addReaderButton_clicked();

    void findBookEdit_editingFinished();

    void findReaderEdit_editingFinished();

    void sortButton_clicked();



private:
    Ui::MainWindow *ui;
    Library* library;
};





#endif // MAINWINDOW_H
