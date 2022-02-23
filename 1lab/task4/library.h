#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include "reader.h"
#include "borrowedbook.h"


class Library
{
public:
    Library();
    ~Library();
    void addReader(Reader reader);
    void addBook(Book book);

    void setBooksAmount(int num);
    void setReadersAmount(int num);
    void setBorrowedBooksAmount(int num);

    int getBooksAmount();
    int getReadersAmount();
    int getBorrowedBooksAmount();

    Book* booksList = nullptr;
    Reader* readersList = nullptr;
    Reader* listOfDebtors = nullptr; //список должников
    BorrowedBook* borrowedBooksList = nullptr;

private:
    int bookAmount = 0;
    int readersAmount = 0;
    int borrowedBooksAmount = 0;


};


#endif // LIBRARY_H
