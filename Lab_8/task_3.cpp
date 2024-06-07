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
            
            delete current;
        }
    }

    int pathMax(int x, int y)
    {
        int max = INT8_MIN;
        Node *current = findLCA(x, y);

        while (1)
        {
            if(current->data > max)
                max = current->data;
            if(current->data == y)
                break;
            else if(current->data < y)
                current = current->right;
            else
                current = current->left;
        }
        return max;
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
    
    int n, _x, _y;
    std::cin >> n;

    while (n--)
    {
        std::cin >> _x >> _y;
        std::cout << bst.pathMax(_x, _y) << std::endl;
    }

    return 0;
}