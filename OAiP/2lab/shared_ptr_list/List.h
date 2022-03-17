#ifndef LIST_H
#define LIST_H

#include "smart_ptrs.h"
#include <iostream>
#include <string>
#include <fstream>
#include <QMessageBox>

struct Node
{
    std::string data;
	shared_ptr<Node> next;

    Node(std::string data = 0)
	{
		this->data = data;
		this->next = shared_ptr<Node>(nullptr);
	}
};



class StringList
{
private:
	shared_ptr<Node> head;

public:
    StringList()
	{
		head = shared_ptr<Node>(nullptr);
	}
    ~StringList(){}

    void push_back(const std::string& data) {
        shared_ptr<Node> newNode = shared_ptr<Node>(new Node(data));

        if (head.isNull()) {
            head = newNode;
            return;
        }

        shared_ptr<Node> temp = head;
        while (!temp->next.isNull()) {
            temp = temp->next;
        }

        temp->next = newNode;
	}

    void printInFile(QWidget* parent = nullptr) {
        shared_ptr<Node> temp(head);

        std::ofstream fout("list.txt");

        if (head.isNull()) {
            std::cout << "List empty" << std::endl;
            QMessageBox::warning(parent, "Error", "List empty");
            return;
        }

        while (!temp.isNull()) {
            fout << temp->data << "\n";
            temp = temp->next;
        }
    }


	void deleteNode(int nodeOffset) {
		shared_ptr<Node> temp1 = head;
		shared_ptr<Node> temp2(nullptr);

		int ListLen = 0;

		if (head.isNull()) {
			std::cout << "List empty." << std::endl;
			return;
		}

		while (!temp1.isNull()) {
			temp1 = temp1->next;
			ListLen++;
		}

		if (ListLen < nodeOffset) {
			std::cout << "Index out of range" << std::endl;
			return;
		}

		temp1 = head;

		if (nodeOffset == 1) {
			head = head->next;
			return;
		}

		while (nodeOffset-- > 1) {
			temp2 = temp1;

			temp1 = temp1->next;
		}

		temp2->next = temp1->next;
	}
};


#endif
