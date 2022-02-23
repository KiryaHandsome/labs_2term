#include "borrowedbook.h"

BorrowedBook::BorrowedBook(int readerCode, int bookCode, QDate dateOfIssue, int backPeriod, QDate backDate)
    : readerCode(readerCode), bookCode(bookCode), dateOfIssue(dateOfIssue), backPeriod(backPeriod), backDate(backDate)
{

}

void BorrowedBook::setReaderCode(int code)
{
    this->readerCode = code;
}

void BorrowedBook::setBookCode(int code)
{
    this->bookCode = code;
}

void BorrowedBook::setDateOfIssue(QDate date)
{
    dateOfIssue = date;
}

void BorrowedBook::setBackPeriod(int days)
{
    backPeriod = days;
}

void BorrowedBook::setBackDate(QDate date)
{
    backDate = date;
}

int BorrowedBook::getReaderCode() const
{
    return readerCode;
}

int BorrowedBook::getBookCode() const
{
    return bookCode;
}

QDate BorrowedBook::getDateOfIssue() const
{
    return dateOfIssue;
}

int BorrowedBook::getBackPeriod() const
{
    return backPeriod;
}

QDate BorrowedBook::getBackDate() const
{
    return backDate;
}
