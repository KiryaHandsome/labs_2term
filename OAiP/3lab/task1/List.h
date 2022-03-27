#pragma once

#include "book.h"
#include <iostream>
#include <QString>
#include <QStringList>





template<class T>
struct Node
{
    Node() : data(T()) {}
    Node(T data): data(data){}
    T data;
    Node* next = nullptr;
    Node* prev = nullptr;
};

template<class T>
void quickSort(Node<T>* l, Node<T>* h);

template<class T>
class List
{
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    size_t sz = 0;
    Node<T>* m_end = nullptr;
public:
    List(): m_end(new Node<T>())
    {
        m_end->data = T();
    }

    ~List()
    {
        if (sz > 0) {
            Node<T>* curr = head->next;
            while (curr) {
                delete curr->prev;
                curr = curr->next;
            }
        }
        delete m_end;
    }

    class iterator {
    private:
        Node<T>* ptr = nullptr;
        List<T>* list = nullptr;
    public:
        iterator() { }
        iterator(Node<T>* ptr, List<T>* list) : ptr(ptr), list(list) { }
        ~iterator() { }

        void operator++()
        {
            if (ptr) ptr = ptr->next;
        }

        T& operator*()
        {
            if (ptr) {
                return ptr->data;
            }
            /*else {
                throw exception;
            }*/
        }

        bool operator!=(const iterator& it)
        {
            return !(list == it.list && ptr == it.ptr);

        }
    };

    void insert(T data, int pos)
    {
        if (pos > 0 && pos <= sz + 1) {
            Node<T>* newNode = new Node<T>(data);
            if (sz == 0) {
                newNode->next = newNode->prev = nullptr;
                head = tail = newNode;
                tail->next = m_end;
                m_end->prev = tail;
            }
            else if (pos == 1) {
                newNode->next = head;
                newNode->prev = nullptr;
                head->prev = newNode;
                head = newNode;
            }
            else if (pos == sz + 1) {
                newNode->next = m_end;
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
                m_end->prev = tail;
            }
            else {
                Node<T>* curr = head;
                for (size_t i = 1; i < pos; ++i) {
                    curr = curr->next;
                }
                newNode->prev = curr->prev;
                newNode->next = curr;
                curr->prev->next = newNode;
                curr->prev = newNode;
            }
            ++sz;
        }
    }

    void erase(int pos)
    {
        if (pos > 0 && pos <= sz) {
            if (sz == 1) {
                delete head;
                head = tail = m_end->prev = nullptr;
            }
            else if (pos == 1) {
                head = head->next;
                delete head->prev;
                head->prev = nullptr;
            }
            else if (pos == sz) {
                tail = tail->prev;
                delete tail->next;
                tail->next = m_end;
                m_end->prev = tail;
            }
            else {
                Node<T>* curr = head;
                for (size_t i = 1; i < pos; ++i) {
                    curr = curr->next;
                }
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                delete curr;
            }
            --sz;
        }
    }

    iterator begin() { return iterator(head, this); }

    iterator end() { return iterator(m_end, this); }

    size_t size() const { return sz; }

    bool isEmpty() const { return sz == 0; }

    void print() {
        if (sz > 0) {
            Node<T>* curr = head;
            for (int i = 0; i < sz; ++i) {
                std::cout << curr->data << " ";
                curr = curr->next;
            }
            std::cout << "\n";
        }
        else {
            std::cout << "List is empty";
        }
    }
    void sort()
    {
        if (sz > 1) {
            quickSort(head, tail);
        }
    }
};




template<class T>
Node<T>* partition(Node<T>* l, Node<T>* h) {
    Book x = h->data;

    Node<T>* i = l->prev;

    for (Node<T>* j = l; j != h; j = j->next) {
        if (j->data.year <= x.year) {
            i = (i == nullptr) ? l : i->next;

            swap(&(i->data), &(j->data));
        }
    }
    i = (i == nullptr) ? l : i->next;
    swap(&(i->data), &(h->data));
    return i;
}

template<class T>
void quickSort(Node<T>* l, Node<T>* h) {
    if (h != nullptr && l != h && l != h->next) {
        Node<T>* p = partition(l, h);
        quickSort(l, p->prev);
        quickSort(p->next, h);
    }
}

