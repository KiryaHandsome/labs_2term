#include "book.h"

Book::Book(int code, QString authorSurname, QString title, int year, QString language)
    : code(code), authorSurname(authorSurname), title(title), year(year), language(language)
{

}
Book::~Book()
{

}

void Book::setBookCode(int code)
{
    this->code = code;
}

void Book::setAuthorSurname(QString surname)
{
    this->authorSurname = surname;
}

void Book::setTitle(QString title)
{
    this->title = title;
}

void Book::setYear(int year)
{
    this->year = year;
}

void Book::setLanguage(QString language)
{
    this->language = language;
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
