#include "library.h"

Library::Library()
{

}
Library::~Library()
{

}
void Library::addReader(Reader reader)
{

}

void Library::addBook(Book book)
{

}


void Library::setBooksAmount(int num)
{
    bookAmount = num;
}

void Library::setReadersAmount(int num)
{
    readersAmount = num;
}
void Library::setBorrowedBooksAmount(int num)
{
    borrowedBooksAmount = num;
}

int Library::getBooksAmount()
{
    return bookAmount;
}
int Library::getReadersAmount()
{
    return readersAmount;
}
int Library::getBorrowedBooksAmount()
{
    return borrowedBooksAmount;
}
