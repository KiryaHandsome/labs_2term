#ifndef C_LIST_H
#define C_LIST_H

template<class T>
class List
{
    template<class U>
    struct Node {
        Node() { }
        Node(const U& value) : data(value) { }
        U data;
        Node* next;
        Node* prev;
    };
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    size_t m_size = 0;
public:
    List() { }
    ~List() {
        Node<T>* temp = head;
        for (int i = 0; i < m_size - 1; ++i) {
            temp = temp->next;
            delete temp->prev;
        }
        delete temp;
    }
    void push_back(const T& value) {
        Node<T>* new_node = new Node<T>(value);
        if (m_size == 0) {
            head = tail = new_node;
        }
        else {
            Node<T>* tmp = tail;
            tail = new Node<T>(value);
            tail->prev = tmp;
            tmp->next = tail;
        }
        tail->next = head;
        head->prev = tail;
        ++m_size;
    }

    size_t size() const { return m_size; }



    class iterator
    {
    private:
        Node<T>* node;
    public:
        iterator() { }
        iterator(Node<T>* node) : node(node) {}
        iterator(const iterator& other) :node(other.node) {}
        void operator++() { node = node->next; }
        void operator--() { node = node->prev; }
        bool operator!=(const iterator& other) { return node->data == other.node->data; }
        T& operator*() { return node->data; }

        void operator=(const iterator& other) {
            node = other.node;
        }
    };

    iterator begin() { return iterator(head); }
    iterator end() { return iterator(tail); }
};

#endif // C_LIST_H
