#ifndef BORROWEDBOOK_H
#define BORROWEDBOOK_H

#include <QDate>

class BorrowedBook  //отд
{
public:
    BorrowedBook(int readerCode = 0, int bookCode = 0, QDate dateOfIssue = QDate(1, 1, 1001), int backPeriod = 30, QDate backDate = QDate(10, 10, 2010));

    void setReaderCode(int code);
    void setBookCode(int code);
    void setDateOfIssue(QDate date);
    void setBackPeriod(int days);
    void setBackDate(QDate date);

    int getReaderCode() const;
    int getBookCode() const;
    QDate getDateOfIssue() const;
    int getBackPeriod() const;
    QDate getBackDate() const;

private:
    int readerCode;
    int bookCode;
    QDate dateOfIssue; //дата выдачи
    int backPeriod;    //требуемый срок возврата в днях
    QDate backDate;    //реальная дата возврата книги

};

#endif // BORROWEDBOOK_H
