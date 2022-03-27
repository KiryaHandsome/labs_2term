#ifndef LIST_H
#define LIST_H

#include "date.h"
#include <QDate>
#include <QString>
#include <QStringList>
#include <QTime>
#include <iostream>



struct Call
{
  Date date;
  int code;
  QString town;
  int duration; // in minutes
  QString tariff;
  QString number;

  Call() {}
  Call(Date date, int code, QString town, int duration, QString tariff, QString number)
    : date(date), code(code), town(town), duration(duration), tariff(tariff), number(number) {}
  ~Call() {}

  bool isCorrectCall(QString string)
  {
    QStringList data = string.split("|");
    if (data.size() != 6 || data[1].toInt() <= 0 || containsDigit(data[2]) ||
        data[3].toInt() <= 0 || data[5].toInt() <= 0 ||
        !Date().isCorrect(data[0])) {
      return false;
    }
    return true;
  }

  Call convertToCall(QString call)
  {
    QStringList info = call.split("|");
    Date date;
    date.readDate(info[0]);

    return Call(date, info[1].toInt(), info[2], info[3].toInt(), info[4], info[5]);
  }
};



template<class T>
class vector {
private:
    T* arr;
    size_t sz = 0;
    size_t cap = 32;

    size_t* refCount;
public:
    vector() : arr(new T[32]), refCount(new size_t(0))
    {
        ++(*refCount);
    }
    vector(const vector<T>& v) {
        arr = v.arr;
        sz = v.sz;
        cap = v.cap;
        refCount = v.refCount;
        ++(*refCount);
    }

    ~vector()
    {
        --(*refCount);
        if(*refCount == 0) delete[] arr;
    }


    void push_back(T data)
    {
        if (sz == cap) {
            grow();
        }
        arr[sz] = data;
        ++sz;
    }

    void erase(size_t pos)
    {
        if (pos < sz) {
            T* newArr = new T[cap];
            int counter = 0;
            for (int i = 0; i < sz; ++i) {
                if (i != pos) {
                    newArr[counter] = arr[i];
                    ++counter;
                }
            }
            --sz;
            delete[] arr;
            arr = newArr;
        }
    }

    void insert(T data, size_t pos)
    {
        if (pos <= sz) {
            if (sz == cap) {
                grow();
            }
            T* newArr = new T[cap];
            int counter = 0;
            for (int i = 0; i < sz + 1; ++i) {
                if (i == pos) {
                    newArr[i] = data;
                }
                else {
                    newArr[i] = arr[counter];
                    counter++;
                }
            }
            delete[] arr;
            arr = newArr;
            ++sz;
        }
    }

    T& operator[](size_t indx) { return arr[indx]; }

    size_t size() const { return sz; }
    size_t capacity() const { return cap; }

private:

    void grow()
    {
        cap *= 2;
        T* newArr = new T[cap];
        for (int i = 0; i < sz; ++i) {
            newArr[i] = arr[i];
        }
        delete arr;
        arr = newArr;
    }
};




template<class T>
class List
{
private:
    vector <T> data;
public:
    List() { }
    ~List() { }

    void insert(T param, size_t pos)
    {
        data.insert(param, pos);
    }

    void push_back(T param)
    {
        data.push_back(param);
    }

    void erase(size_t pos)
    {
        data.erase(pos);
    }

    class iterator
    {
    private:
        vector<T> arr;
        size_t indx;
    public:
        iterator(const vector<T>& arr, size_t indx) : arr(arr), indx(indx) { }
        iterator(const iterator& it): arr(it.arr), indx(it.indx) { }


        void operator++() { ++indx; }

        void operator--() { --indx; }

        T& operator*() { return arr[indx]; }

        bool operator!=(const iterator& it) { return !(indx == it.indx); }

    };

    iterator begin() { return iterator(data, 0); }

    iterator end() { return iterator(data, data.size()); }

    size_t size() const { return data.size(); }

    bool isEmpty() const { return data.size() == 0; }

    vector<T> getArr() { return data; }

};

void swap(Call* l, Call* r);
void quickSort(vector<Call> data, int first, int last);



#endif







