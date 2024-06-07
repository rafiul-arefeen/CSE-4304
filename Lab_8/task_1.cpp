#include <iostream>
#include <stack>

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int _data) : data(_data) {}
};

class BST
{
private:
    Node *root;

public:
    BST() : root(nullptr) {}

    bool insert(int val)
    {
        if (root == nullptr)
        {
            Node *newNode = new Node(val);
            root = newNode;
            return true;
        }
        else
        {
            Node *current = root;
            Node *parent = nullptr;

            while (current != nullptr)
            {
                parent = current;

                if (val < current->data - 3)
                    current = current->left;
                else if (val > current->data + 3)
                    current = current->right;
                else
                    return false;
            }

            if (val < parent->data)
            {
                Node *newNode = new Node(val);
                parent->left = newNode;
                return true;
            }
            else if (val > parent->data)
            {
                Node *newNode = new Node(val);
                parent->right = newNode;
                return true;
            }
            else
                return false;
        }
    }

    void inorderTraversal()
    {
        if (root == nullptr)
            return;
        else
        {
            std::stack<Node *> stack;
            Node *current = root;

            while (current != nullptr || !stack.empty())
            {
                while (current != nullptr)
                {
                    stack.push(current);
                    current = current->left;
                }

                current = stack.top();
                std::cout << current->data << " ";
                stack.pop();

                current = current->right;
            }

            delete current;
        }
    }
};

int main()
{
    BST bst;
    int val;

    while (1)
    {
        std::cin >> val;
        if (val == -1)
            break;

        if (bst.insert(val))
        {
            bst.inorderTraversal();
            std::cout << std::endl;
        }
        else
        {
            bst.inorderTraversal();
            std::cout << "(Reservation failed)" << std::endl;
        }
    }

    return 0;
}