#include "borrowedbook.h"

BorrowedBook::BorrowedBook(Date dateOfIssue, Date backDate, int bookCode, int readerCode, int backPeriod)
    : bookCode(bookCode), readerCode(readerCode),
      backPeriod(backPeriod), dateOfIssue(dateOfIssue), backDate(backDate)
{

}

int BorrowedBook::getBookCode()
{
    return bookCode;
}
int BorrowedBook::getReaderCode()
{
    return readerCode;
}
Date BorrowedBook::getDateOfIssue()
{
    return dateOfIssue;
}
int BorrowedBook::getBackPeriod()
{
    return backPeriod;
}
Date BorrowedBook::getBackDate()
{
    return backDate;
}
