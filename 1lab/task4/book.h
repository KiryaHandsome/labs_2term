#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book
{
public:
    Book(int code = 0, QString authorSurname = "Dostoevskiy", QString title = "Idiot", int year = 1990, QString language = "Russian");
    ~Book();

    void setBookCode(int code);
    void setAuthorSurname(QString surname);
    void setTitle(QString title);
    void setYear(int year);
    void setLanguage(QString language);

    int getBookCode() const;
    QString getAuthorSurname() const;
    QString getTitle() const;
    int getYear() const;
    QString getLanguage() const;

private:
    int code;         //код книги
    QString authorSurname;
    QString title;
    int year;         //год публикации
    QString language; //язык издания
};

#endif // BOOK_H
