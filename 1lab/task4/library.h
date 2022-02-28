#ifndef LIBRARY_H
#define LIBRARY_H

#include <QMainWindow>
#include "book.h"
#include "reader.h"
#include "borrowedbook.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Library; }
QT_END_NAMESPACE

class Library : public QMainWindow
{
    Q_OBJECT

public:
    Library(QWidget *parent = nullptr);
    ~Library();

    void clearTable();

    void readBooksFromFile();

    void readReadersFromFile();

    void rewriteBooksInFile();

    void rewriteReadersInFile();


    int borrowedBooksAmount;
    int booksAmount;
    int readersAmount;

private slots:
    void booksButton_clicked();

    void readersBooksButton_clicked();

    void readersButton_clicked();

    void debtorsButton_clicked();

    void addBookButton_clicked();

    void addReaderButton_clicked();

    void sortReadersButton_clicked();

    void sortBooksButton_clicked();

    void findBookEdit_textChanged(const QString &arg1);

    void findReaderEdit_textChanged(const QString &arg1);

    void changeBookButton_clicked();

    void changeReaderButton_clicked();

    void deleteBookButton_clicked();

    void deleteReaderButton_clicked();



private:
    Ui::Library *ui;
    Book* bookList;
    Reader* readerList;
    BorrowedBook* borrowedBooks;
};

bool containsDigit(const QString& string);

#endif // LIBRARY_H
