#ifndef READER_H
#define READER_H

#include <QString>

class Reader
{
public:
    Reader(int code = 0, QString FIO = "Sasha", QString homeAddrress = "Sovetskaya 23", QString contactNumber = "+12345678");
    ~Reader();

    void setCode(int code);
    void setFIO(QString FIO);
    void setContactNumber(QString number);
    void setHomeAddress(QString address);

    int getCode() const;
    QString getHomeAddress() const;
    QString getFIO() const;
    QString getContactNumber() const;

private:        //код читателя, ФИО читателя, домашний адрес, контактный телефон
    int code;
    QString FIO; //фио читателя
    QString homeAddress;
    QString contactNumber;
};

#endif // READER_H
