#ifndef STACK_H
#define STACK_H

#include "smart_ptrs.h"
#include <QMessageBox>


class Book
{
private:
    int code;
    std::string authorSurname;
    std::string title;
    int year;
public:
    Book(int code = 0, std::string authorSurname = "", std::string title = "", int year = 0)
        : code(code), authorSurname(authorSurname), title(title), year(year)
    {
    }
    ~Book()
    {
    }

    int getBookCode() const { return code; }

    std::string getAuthorSurname() const { return authorSurname; }

    std::string getTitle() const { return title; }

    int getYear() const { return year; }


    //friend std::ostream& operator<<(std::ostream& out, const Book& book);

};

/*std::ostream& operator<<(std::ostream& out, const Book& book)
{
    out << book.code << " " << book.title << " " << book.authorSurname << " " << book.year;
    return out;
}*/

class BookStack
{
private:
    unique_ptr<Book[]> book_list;
    int amount = 0;

public:

    BookStack()
    {
    }

    void push(const Book& item)
    {
        unique_ptr<Book[]> tmp(new Book[amount]);

        for (int i = 0; i < amount; i++){
            tmp[i] = book_list[i];
        }


        book_list.reset(new Book[amount + 1]);

        amount++;

        for (int i = 0; i < amount - 1; i++)
            book_list[i] = tmp[i];

        book_list[amount - 1] = item;
    }

    Book pop(QWidget* parent)
    {
        if (amount == 0) {
            QMessageBox::warning(parent, "Error", "Stack is empty");
            return Book();
        }
        amount--;
        return book_list[amount];
    }


    Book Head(QWidget* parent)
    {
        if (amount == 0) {
            std::cout << "Stack is empty" << std::endl;
            QMessageBox::warning(parent, "Error", "Stack is empty");
            return Book();
        }  
        return book_list[amount - 1];
    }

    ~BookStack()
    {
    }

    int getAmount() const { return amount; }

    bool isEmpty() const { return amount == 0; }
};



#endif
