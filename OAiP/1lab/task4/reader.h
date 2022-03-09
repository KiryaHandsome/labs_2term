#ifndef READER_H
#define READER_H

#include <QString>
#include "book.h"

class Reader
{
public:
    Reader(int code = 0, QString FIO = "none", QString homeAddress = "none", long contactNumber = 0);
    ~Reader();


    Book* book = 0;

    int getCode() const;
    QString getHomeAddress() const;
    QString getFIO() const;
    long getContactNumber() const;


private:
    int code;   //код читателя
    QString FIO; //фио читателя
    QString homeAddress;
    long contactNumber;
};

#endif // READER_H
