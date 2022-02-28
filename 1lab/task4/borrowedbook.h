#ifndef BORROWEDBOOK_H
#define BORROWEDBOOK_H

#include "date.h"

class BorrowedBook
{
public:
    BorrowedBook(Date dateOfIssue = Date(0, 0, 0), Date backDate = Date(0, 0, 0), int bookCode = 0, int readerCode = 0, int backPeriod = 0);
    int getBookCode();
    int getReaderCode();
    Date getDateOfIssue();
    int getBackPeriod();
    Date getBackDate();



private:
    int bookCode;
    int readerCode;
    Date dateOfIssue; //дата выдачи
    int backPeriod;    //требуемый срок возврата в днях
    Date backDate;    //реальная дата возврата книги
};

#endif // BORROWEDBOOK_H
