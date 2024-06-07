#include <iostream>
#include <stack>

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
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
                    current = current->left;
                else
                    current = current->right;
            }

            if (val < parent->data)
                parent->left = newNode;
            else
                parent->right = newNode;
        }
    }

    Node *findLCA(int x, int y)
    {
        Node *current = root;
        while (current != nullptr)
        {
            if (x < current->data && y < current->data)
                current = current->left;
            else if (x > current->data && y > current->data)
                current = current->right;
            else
                return current;
        }
        return nullptr;
    }
};

int main()
{
    int n, val;
    BST tree;

    std::cin >> n;
    while (n--)
    {
        std::cin >> val;
        tree.insert(val);
    }

    int x, y;
    std::cin >> n;
    while (n--)
    {
        std::cin >> x >> y;
        std::cout << tree.findLCA(x, y)->data << " ";
    }

    return 0;
}
