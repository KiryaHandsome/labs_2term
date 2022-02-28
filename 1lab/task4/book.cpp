#include "book.h"
#include <QStringList>

Book::Book(int code, QString authorSurname, QString title, int year, QString language)
    :code(code), authorSurname(authorSurname), title(title), year(year), language(language)
{

}

Book::~Book()
{

}

int Book::getBookCode() const
{
    return code;
}

QString Book::getAuthorSurname() const
{
    return authorSurname;
}

QString Book::getTitle() const
{
    return title;
}

int Book::getYear() const
{
    return year;
}

QString Book::getLanguage() const
{
    return language;
}
