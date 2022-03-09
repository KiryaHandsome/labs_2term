#include "reader.h"
#include <QStringList>

Reader::Reader(int code, QString FIO, QString homeAddress, long contactNumber)
    : code(code), FIO(FIO), homeAddress(homeAddress), contactNumber(contactNumber)
{

}

Reader::~Reader()
{

}

QString Reader::getHomeAddress() const
{
    return homeAddress;
}
int Reader::getCode() const
{
    return code;
}
QString Reader::getFIO() const
{
    return FIO;
}
long Reader::getContactNumber() const
{
    return contactNumber;
}

