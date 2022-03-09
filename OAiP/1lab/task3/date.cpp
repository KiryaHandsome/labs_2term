#include "date.h"
#include <QStringList>
#include <QDate>
#include <QChar>

Date::Date(int day, int month, int year) :
    day(day), month(month), year(year)
{
    if(this->isLeap()) this->Days[1] = 29;
}

int Date::getDay() const { return day; }

int Date::getMonth() const { return month; }

int Date::getYear() const { return year; }

void Date::setDay(int day) { this->day = day; }

void Date::setMonth(int month) { this->month = month; }

void Date::setYear(int year) {
    this->year = year;
    if(this->isLeap()) Days[1] = 29;
    else Days[1] = 28;
}


bool Date::isLeap()
{
    if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0) {
        return true;
    }
    return false;
}

Date Date::nextDay()
{
    int Day = this->day, Month = this->month, Year = this->year;

    if (day >= 28 && day <= 31) {
        if (day == 31 || ((day == 28 || day == 29) && month == Month::February)
            || (day == 30 && (month == Month::April || month == Month::June || month == Month::September || month == Month::November))) {
            Day = 1;
            if (this->month == Month::December) {
                Month = Month::January;
                Year = this->year + 1;
            }
            else {
                Month = this->month + 1;
            }
        }
    }
    else {
        Day = this->day + 1;
    }

    return Date(Day, Month, Year);
}

Date Date::previousDay()
{
    int Day = this->day, Month = this->month, Year = this->year;
    if (day == 1) {
        if (month == January || month == February || month == April || month == June
            || month == August || month == September || month == November) {            //days amount of previous month == 31
            Day = 31;

            if (this->month != January) {
                Month = this->month - 1;
            }
            else {
                Month = December;
                Year = this->year - 1;
            }
        }
        else if (month == May || month == July || month == October || month == December) {      //days amount of previous month == 30
            Day = 30;
        }
        else {
            Day = (this->isLeap() ? 29 : 28);
        }
    }
    else {
        Day = this->day - 1;
    }

    return Date(Day, Month, Year);
}

int Date::daysInThisEra()
{
    int leapYears = year / 4 - year / 100 + year / 400;

    int result = year * 365 + leapYears;

    for (int i = 0; i < month - 1; i++) {
        result += this->Days[i];
    }
    result += day;

    return result;
}

int Date::duration(Date date)
{
    int daysFirst = date.daysInThisEra();
    int daysSecond = this->daysInThisEra();

    return (daysFirst > daysSecond ? daysFirst - daysSecond : daysSecond - daysFirst);
}

short Date::weekNumber()
{
    int a = (14 - 2) / 12;      //formula from internet
    int y = year + 4800 - a;    //http://astro.altspu.ru/~aw/blog/2011/05/calculate-the-number-of-weeks.html
    int m = month + 12 * a - 3;
    int JD = day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
    int d4 = ((((JD + 31741 - (JD % 7)) % 146097) % 36524) % 1461);
    int L = d4 / 1460;
    int d1 = ((d4 - L) % 365) + L;
    int WN = (d1 / 7) + 1;
    return  WN;
}

int Date::daysTillYourBirthday(Date birthdayDate)
{
    int _day = birthdayDate.getDay(), _month = birthdayDate.getMonth(), _year;
    int currDay = QDate::currentDate().day();
    int currMonth = QDate::currentDate().month();
    int currYear = QDate::currentDate().year();

    if (_month > currMonth) {
        _year = currYear;
    }
    else if(_month == currMonth){
        if(_day > currDay){
            _year = currYear;
        } else _year = currYear + 1;
    }
    else {
        _year = currYear + 1;
    }
    int daysFirst = Date(_day, _month, _year).daysInThisEra();
    int daysSecond = Date(currDay, currMonth, currYear).daysInThisEra();

    return daysFirst - daysSecond;
}
bool Date::isCorrect(QString date)
{
    int count_points = 0;
    QStringList list = date.split(QLatin1Char('.'));
    if(list.size() != 3) return false;
    for(int i = 0; i < date.size(); i++){
        if(date[i] == '.') count_points++;
        else if(!QChar(date[i]).isDigit()) return false;
    }
    if(count_points != 2) return false;

    int Day = list[0].toInt();
    int Month = list[1].toInt();
    int Year = list[2].toInt();
    if(Day <= 0 || Month <= 0 || Year <= 0){
        return false;
    }
    else if(Day > 31 || Month > 12 || Year > 9999){
        return false;
    }
    else if(Day == 31 && Month != January && Month != March && Month != May
           && Month != July && Month != August && Month != October && Month != December){
        return false;
    }
    else if(Day >= 29 && Month == February && !((year % 100 != 0 && year % 4 == 0) || year % 400 == 0)) {
        return false;
    }
    else return true;
}

void Date::readDate(QString string)
{
    QStringList list = string.split(QLatin1Char('.'));

    day = list[0].toInt();
    month = list[1].toInt();
    year = list[2].toInt();
}

QString Date::showDate() const
{
    QString string;
    QString day = QString::number(this->day);
    QString month = QString::number(this->month);
    QString year = QString::number(this->year);
    string += (day.size() == 2 ? day : '0' + day) + '.';
    string += (month.size() == 2 ? month : '0' + month) + '.';  //align date to 01.01.0021 format
    for(int i = 0; i < 4 - year.size(); i++) string += '0';
    string += year;
    return string;
}

Date& Date::operator=(const Date& date)
{
    this->day = date.getDay();
    this->month = date.getMonth();
    this->year = date.getYear();
    return *this;
}


