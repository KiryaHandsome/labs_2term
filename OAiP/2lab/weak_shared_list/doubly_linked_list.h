#pragma once

#include "smart_ptrs.h" 
#include <fstream>
#include <QMessageBox>

class DoublyLinkedList
{
private:
	struct Node {
		Node(int val = 0) : value(val) {}
		int value;
		shared_ptr<Node> next;
		weak_ptr<Node> prev;
	};
	shared_ptr<Node> head;
	int size = 0;
public:
	DoublyLinkedList() = default;
	~DoublyLinkedList() = default;

	void insert(int value, int pos = 0)
	{
		shared_ptr<Node> node = make_shared<Node>(value);
		if (size == 0) {
			node->next = node;
			node->prev = node;
			head = node;
			size++;
		}
		else if (pos > size || pos < 0) {
			std::cout << "position is incorrect\n";
		}
		else {
            shared_ptr<Node> p(head->prev);

            for (int i = pos; i > 0; i--) p = p->next;
			node->prev = p;
			node->next = p->next;
			p->next = node;
			node->next->prev = node;
			size++;
            if (pos == 0) {
                head = head->prev.lock();
            }
		}


	}

	void erase(int pos)
	{
		if (size == 0) {
			return;
		}
		if (head == head->next) {
			head.reset(nullptr);	
		}
		else {
			shared_ptr<Node> temp(head->prev);
			if (pos == 0) {
				head = head->next;
			}
			for (int i = pos; i > 0; i--) temp = temp->next;
			temp->next->next->prev = temp;
			temp->next = temp->next->next;

		}
		size--;
	}

    bool printListInFile()
	{
        std::ofstream fout("list.txt");
        if(fout.is_open()){
            if (size == 0) {
                fout << "List is empty\n";
            }
            else {
                shared_ptr<Node> a = head;
                fout << "\nElements of list: ";
                do
                {
                    fout << a->value << " ";
                    a = a->next;
                } while (a != head);
                fout.close();
                return true;
            }
        }
        return false;
	}

};
