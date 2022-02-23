#include "reader.h"

Reader::Reader(int code, QString FIO, QString homeAddress, QString contactNumber)
    : code(code), FIO(FIO), homeAddress(homeAddress), contactNumber(contactNumber)
{

}
Reader::~Reader()
{

}

void Reader::setCode(int code)
{
    this->code = code;
}

void Reader::setFIO(QString FIO)
{
    this->FIO = FIO;
}

void Reader::setContactNumber(QString number)
{
    this->contactNumber = number;
}

int Reader::getCode() const
{
    return code;
}
QString Reader::getFIO() const
{
    return FIO;
}
QString Reader::getContactNumber() const
{
    return contactNumber;
}

void Reader::setHomeAddress(QString address)
{
    homeAddress = address;
}

QString Reader::getHomeAddress() const
{
    return homeAddress;
}
