#pragma once

#include <string>
#include <iostream>
#include <queue>


struct Node
{
    Node(int key, std::string info) : key(key), info(info) { }
    std::string info;
    int key;
    Node* left = nullptr;
    Node* right = nullptr;
    int height = 1;
};

class Tree
{
private:
    Node* root = nullptr;

    bool _isLastDeletionSuccesfull_ = true;
    std::vector<std::pair<int, std::string>> lastTraverse;
public:
    Tree() { }

    ~Tree()
    {
        destroyNode(root);
    }


    void addInfoFromArray(std::vector<std::pair<int, std::string>> arr)
    {
        for (size_t i = 0; i < arr.size(); ++i) {
            insert(arr[i].first, arr[i].second);
        }
    }

    void insert(int key, const std::string& info)
    {
        root = insert(root, key, info);
    }

    std::string search(int key)
    {
        Node* curr = root;
        while (curr) {
            if (curr->key == key) {
                 return curr->info;
            }
            else if (curr->key > key) {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }
        //if found nothing
        return "";
    }

    void deleteNode(int key)
    {
        root = deleteNode(root, key);
    }

    void printInOrder()
    {
        lastTraverse.clear();
        printInOrder(root);
    }

    void printPostOrder()
    {
        lastTraverse.clear();
        printPostOrder(root);
    }

    void printPreOrder()
    {
        lastTraverse.clear();
        printPreOrder(root);
    }

    Node* getRoot() { return root; }

    bool isLastDeletionSuccesfull() {
        bool temp = _isLastDeletionSuccesfull_;
        _isLastDeletionSuccesfull_ = true;
        return temp == true;
    }

    bool isEmpty() const { return root == nullptr; }

    std::vector<std::pair<int, std::string>> getLastTraverseArray()
    {
        return lastTraverse;
    }

private:
    void destroyNode(Node* node) {
        if (node) {
            destroyNode(node->left);
            destroyNode(node->right);
            delete node;
        }
    }

    void printInOrder(Node* node)
    {
        if (node) {
            printInOrder(node->left);
            std::cout << node->info << " ";
            lastTraverse.push_back(std::make_pair(node->key, node->info));
            printInOrder(node->right);
        }
    }

    void printPreOrder(Node* node)
    {
        if (node) {
            std::cout << node->info << " ";
            lastTraverse.push_back(std::make_pair(node->key, node->info));
            printPreOrder(node->left);
            printPreOrder(node->right);
        }
    }

    void printPostOrder(Node* node)
    {
        if (node) {
            printPostOrder(node->left);
            printPostOrder(node->right);
            std::cout << node->info << " ";
            lastTraverse.push_back(std::make_pair(node->key, node->info));
        }
    }

    Node* minValueNode(Node* node)
    {
        Node* current = node;

        /* loop down to find the leftmost leaf */
        while (current->left != nullptr) {
            current = current->left;
        }

        return current;
    }

    int height(Node* node)
    {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    Node* deleteNode(Node* node, int key)
    {
        if (node == nullptr) {
            _isLastDeletionSuccesfull_ = false;
            return node;
        }

        if (key < node->key) {
            node->left = deleteNode(node->left, key);
        }
        else if (key > node->key) {
            node->right = deleteNode(node->right, key);
        }
        else {
            // node with only one child or no child
            if ((node->left == nullptr) || (node->right == nullptr))
            {
                Node* temp = (node->left ? node->left : node->right);
                // No child case
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                }
                else { // One child case
                    *node = *temp; // Copy the contents of the non-empty child
                }
                delete temp;
            }
            else
            {
                //minimal node in right subtree
                Node* temp = minValueNode(node->right);

                // Copy the inorder successor's
                // data to this node
                node->key = temp->key;
                node->info = temp->info;

                // Delete the inorder successor
                node->right = deleteNode(node->right, temp->key);
            }
        }

        // If the tree had only one node
        // then return
        if (node == nullptr) {
            return node;
        }

        //UPDATE HEIGHT OF THE CURRENT NODE
        node->height = 1 + std::max(height(node->left), height(node->right));

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && getBalance(node->left) >= 0)
        {
            return rightRotate(node);
        }
        // Left Right Case
        if (balance > 1 && getBalance(node->left) < 0)
        {
            node->left = leftRotate(node->left);
            return rightRotate(root);
        }
        // Right Right Case
        if (balance < -1 && getBalance(node->right) <= 0)
        {
            return leftRotate(node);
        }
        // Right Left Case
        if (balance < -1 && getBalance(node->right) > 0)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* rightRotate(Node* y)
    {
        std::cout << "rightRotate\n";
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = std::max(height(y->left), height(y->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;

        // Return new root
        return x;
    }

    Node* leftRotate(Node* x)
    {
        std::cout << "leftRotate\n";
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = std::max(height(x->left), height(x->right)) + 1;
        y->height = std::max(height(y->left), height(y->right)) + 1;

        // Return new root
        return y;
    }

    // Get Balance factor of node N
    int getBalance(Node* N)
    {
        if (N == nullptr) {
            return 0;
        }
        return height(N->left) - height(N->right);
    }

    Node* insert(Node* node, int key, const std::string& info)
    {
        if (node == nullptr) {
            return(new Node(key, info));
        }

        if (key < node->key) {
            node->left = insert(node->left, key, info);
        }
        else if (key > node->key) {
            node->right = insert(node->right, key, info);
        }
        else {	//if key == node->key
            return node;
        }
        // 2. Update height of this ancestor node
        node->height = 1 + std::max(height(node->left), height(node->right));

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && key < node->left->key) {
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && key > node->right->key) {
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        /* return the (unchanged) node pointer */
        return node;
    }
};


class MyTree : public Tree
{
public:
    int numberOfNodesWithOneChild()
    {
        if(this->getRoot() == nullptr) return 0;
        //breadth-first search
        std::queue<Node*> queue;
        queue.push(getRoot());
        int answer = 0;

        while (!queue.empty())
        {
            Node* curr = queue.front();
            queue.pop();
            if (curr->left) {
                queue.push(curr->left);
            }
            if (curr->right) {
                queue.push(curr->right);
            }

            //look on childs
            if ((curr->right && !curr->left) || (!curr->right && curr->left)) {
                ++answer;
            }
        }

        return answer;
    }
};
