#ifndef QUEUE_H
#define QUEUE_H
#include "smart_ptrs.h"


template <class T>
class Queue
{
private:
    shared_ptr<T[]> data;
    size_t m_size;
    size_t m_capacity;
    short m_front;
    short m_back;
public:
    Queue() : data(new T[20]), m_capacity(20), m_size(0), m_front(0), m_back(0) {}
    ~Queue() {}

    void push(const T& value) {
        if (m_size == m_capacity) {
            T* new_data = new T[m_size * 2];
            for (int i = 0, j = m_front; i <= m_back - m_front; ++i, ++j) {
                new_data[i] = data[j];
            }
            data.reset(new_data);
            m_capacity = m_size * 2;
            m_front = 0;
        }
        m_back = m_size++;
        data[m_back] = value;
    }

    void pop() {
        if (m_size == 1) {
            m_front = m_back = 0;
        }
        else {
            ++m_front;
        }
        --m_size;
    }

    const T& front() { return data[m_front]; }

    const T& back() { return data[m_back]; }

    bool isEmpty() { return m_size == 0; }

    size_t size() const { return m_size; }
};



#endif // !QUEUE_H

