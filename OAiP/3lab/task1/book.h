#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <QStringList>

bool containsDigit(const QString &string);

struct Book
{
    Book(int num, QString author, QString title, int year, QString publisher, int pages)
        : regNumber(num), author(author), title(title), year(year), publisher(publisher), pages(pages)
    {
    }
    Book() = default;
    Book(const Book&) = default;
    ~Book() = default;

    int regNumber;
    QString author;
    QString title;
    int year;	//year of publication
    QString publisher;
    int pages;

    bool isCorrectBook(const QString &str);

    Book convertToBook(const QString&);
};


void swap(Book* a, Book* b);




#endif // BOOK_H
