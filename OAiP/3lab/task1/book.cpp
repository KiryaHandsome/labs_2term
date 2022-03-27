#include "book.h"

Book Book::convertToBook(const QString &str) // split by '\'
{
  QStringList list = str.split('|');
  return Book(list[0].toInt(), list[1], list[2], list[3].toInt(), list[4],
              list[5].toInt());
}

bool containsDigit(const QString &string) {
  for (int i = 0; i < string.size(); i++) {
    if (string[i].isDigit())
      return true;
  }
  return false;
}
bool Book::isCorrectBook(const QString &str) // split by '\'
{
     QStringList list = str.split('|');
     if (list.size() != 6 || list[0].toInt() <= 0 || containsDigit(list[1]) || list[3].toInt() <= 0 ||
         list[3].toInt() > 2022 || list[5].toInt() <= 0) {
       return false;
     }
     return true;
}
void swap(Book* a, Book* b) {
    Book t = *a;
    *a = *b;
    *b = t;
}
