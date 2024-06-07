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

    int height(Node *current)
    {
        if (current == nullptr)
            return 0;
        int leftHeight = height(current->left);
        int rightHeight = height(current->right);

        return 1 + std::max(leftHeight, rightHeight);
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
                parent->left = newNode;
            else
                parent->right = newNode;
        }
    }

    int findDiameter()
    {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return leftHeight + rightHeight + 1;
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

    std::cout << tree.findDiameter();

    return 0;
}
