#include <iostream>
#include <stack>

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int subtree_size;

    Node(int _data) : data(_data), left(nullptr), right(nullptr), subtree_size(1) {}
};

class BST
{
private:
    Node *root;

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
                {
                    current->subtree_size++;
                    current = current->left;
                }
                else
                {
                    current->subtree_size++;
                    current = current->right;
                }
            }

            if (val < parent->data)
                parent->left = newNode;
            else
                parent->right = newNode;

            delete current;
        }
    }

    int countResv(int val)
    {
        int count = 0;
        Node *current = root;

        while (current != nullptr)
        {
            if (val > current->data)
            {
                count++;
                if (current->left != nullptr)
                    count += current->left->subtree_size;

                current = current->right;
            }
            else
                current = current->left;
        }
        delete current;
        return count;
    }
};

int main()
{
    int val;
    BST bst;
    while (1)
    {
        std::cin >> val;
        if (val == -1)
            break;

        bst.insert(val);
    }

    int n;
    std::cin >> n;

    while (n--)
    {
        std::cin >> val;
        std::cout << bst.countResv(val) << std::endl;
    }

    return 0;
}