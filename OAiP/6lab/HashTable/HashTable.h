#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <iostream>
                                                                                                                                                                                                                                                                                                                                                                                                                                        #include <stack>
                                                                                                                                                                                                                                                                                                                                                                                                                                        #include <vector>
                                                                                                                                                                                                                                                                                                                                                                                                                                        using namespace std;
class HashTable
{
private:
    size_t _size = 0;
    size_t _capacity = 0;
    vector<stack<pair<int, int>>> arr;
public:
    HashTable(): _capacity(100)
    {
        arr.resize(100);
    }

    HashTable(size_t count) :_capacity(count)
    {
        arr.resize(count);
        _capacity = count;
    }

    ~HashTable() {}

    int search(int key) {
        int result = INT_MIN;
        stack<pair<int, int>> stack;
        auto hash_key = this->hash(key);
        while (!arr[hash_key].empty()) {
            if (arr[hash_key].top().first == key) {
                result = arr[hash_key].top().second;
                break;
            }
            stack.push(arr[hash_key].top());
            arr[hash_key].pop();
        }

        while (!stack.empty()) {
            arr[hash_key].push(stack.top());
            stack.pop();
        }
        return result;
    }

    bool insert(int key, int value) {
        if(_size != _capacity){
            size_t hash_value = this->hash(key);
            stack<pair<int, int>> stack;
            while (!arr[hash_value].empty()) {
                if (arr[hash_value].top().first == key) {
                    while (!stack.empty()) {
                        arr[hash_value].push(stack.top());
                        stack.pop();
                    }
                    return false;
                }
                stack.push(arr[hash_value].top());
                arr[hash_value].pop();
            }

            while (!stack.empty()) {
                arr[hash_value].push(stack.top());
                stack.pop();
            }
            arr[hash_value].push(make_pair(key, value));
            ++_size;

            return true;
        } else {
            return false;
        }

    }

    bool remove(int key) {
        stack<pair<int, int>> stack;
        auto hash_key = this->hash(key);
        bool isRemoved = false;

        while (!arr[hash_key].empty()) {
            if (arr[hash_key].top().first == key) {
                arr[hash_key].pop();
                isRemoved = true;
                --_size;
                break;
            }
            stack.push(arr[hash_key].top());
            arr[hash_key].pop();
        }

        while (!stack.empty()) {
            arr[hash_key].push(stack.top());
            stack.pop();
        }
        return isRemoved;
    }

    size_t size() const { return _size; }

    size_t hash(int key) {
        const int V = 19;
        size_t hash_value = _capacity - key + V;
        return hash_value % _capacity;
    }

    bool isFull() const { return _size == _capacity; }
    auto getHashTableArray() { return arr; }

};



#endif // HASHTABLE_H
