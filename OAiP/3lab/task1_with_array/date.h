#ifndef DATE_H
#define DATE_H

#include <QTextStream>

class Date
{
public:
    Date(int day = 1, int month = 1, int year = 2022);
    Date nextDay();
    Date previousDay();
    bool isLeap();
    short weekNumber();
    int daysTillYourBirthday(Date birthdaydate);
    int duration(Date date);
    int Days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    enum Month {
        January = 1,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December
    };

    int getDay() const;

    int getMonth() const;

    int getYear() const;

    int daysInThisEra();

    void setDay(int day);

    void setMonth(int month);

    void setYear(int year);

    void readDate(QString string);

    QString showDate() const;

    int getAmount() const;

    bool isCorrect(QString date);

    Date& operator=(const Date&);

private:
    int day;
    int month;
    int year;
};

bool containsDigit(const QString& string);

#endif // DATE_H
