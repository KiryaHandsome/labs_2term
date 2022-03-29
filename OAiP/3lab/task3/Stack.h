#ifndef STACK_H
#define STACK_H

#include <iostream>


template<class T>
class vector;

template<class T>
class Stack
{
private:
    vector<T> data;
public:
    Stack() { }
    ~Stack(){ }

    void push(T data)
    {
        this->data.push_back(data);
    }

    T top()
    {
        return data[data.size() - 1];
    }

    void pop()
    {
        data.erase(data.size() - 1);
    }

    bool isEmpty() const { return data.size() == 0; }

    size_t size() const { return data.size(); }


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
        refCount++;
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
        if (*refCount == 0) {
            delete[] arr;
            delete refCount;
        }
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

    void clear()
    {
        if (sz != 0) {
            --(*refCount);
            if (*refCount == 0) {
                delete[] arr;
                delete refCount;
            }
            arr = new T[cap];
            refCount = new size_t(1);
        }

    }

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

#endif // STACK_H
