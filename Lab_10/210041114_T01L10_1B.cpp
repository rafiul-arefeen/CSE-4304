#include <iostream>

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *parent;
    int height;

    Node(int _data) : data(_data), left(nullptr), right(nullptr), parent(nullptr), height(0) {}
};

class BST
{
private:
    Node *root;
    void inorder(Node *current)
    {
        if (current != nullptr)
        {
            inorder(current->left);
            std::cout << current->data << "(" << balanceFactor(current) << ") ";
            inorder(current->right);
        }
    }
    void updateHeight(Node *current)
    {
        int h = 1;
        while (current != nullptr)
        {
            if (current->height > h)
                break;

            if (current->height < h)
                current->height = h;

            current = current->parent;
            h++;
        }
    }
    int balanceFactor(Node *current)
    {
        if (current->left == nullptr && current->right == nullptr)
            return 0;
        else if (current->left == nullptr)
            return -1 - current->right->height;
        else if (current->right == nullptr)
            return current->left->height + 1;
        else
            return current->left->height - current->right->height;
    }

public:
    BST() : root(nullptr) {}

    void insert(int val)
    {
        Node *newNode = new Node(val);
        if (root == nullptr)
        {
            root = newNode;
            return;
        }
        else
        {
            Node *current = root;
            Node *parent = nullptr;

            while (current != nullptr)
            {
                parent = current;

                if (val < current->data)
                    current = current->left;
                else
                    current = current->right;
            }

            if (val < parent->data)
            {
                newNode->parent = parent;
                parent->left = newNode;
            }
            else
            {
                newNode->parent = parent;
                parent->right = newNode;
            }

            updateHeight(parent);
        }
    }

    void print()
    {
        inorder(root);
    }
};

int main()
{
    int val;
    BST tree;

    while (std::cin >> val)
    {
        if (val == -1)
            break;
        else
        {
            tree.insert(val);
            tree.print();
            std::cout << std::endl;
        }
    }

    return 0;
}