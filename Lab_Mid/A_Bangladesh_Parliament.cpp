#include <iostream>
#include <stack>
#include <queue>

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *parent;
    Node(int _data) : data(_data), left(nullptr), right(nullptr), parent(nullptr) {}
};

class BST
{
private:
    Node *root;
    void _evenTraversal(Node *current)
    {
        if (current != nullptr)
        {
            _evenTraversal(current->right);
            _evenTraversal(current->left);
            std::cout << current->data << std::endl;
        }
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
            Node *up = nullptr;
            while (current != nullptr)
            {
                up = current;
                if (val < current->data)
                    current = current->left;
                else
                    current = current->right;
            }
            if (val < up->data)
            {
                newNode->parent = up;
                up->left = newNode;
            }
            else
            {
                newNode->parent = up;
                up->right = newNode;
            }
        }
    }
    void evenTraversal()
    {
        _evenTraversal(root);
    }
};

int main()
{
    int n, val;
    std::vector<int> vec;
    BST tree;

    std::cin >> n;
    while (n--)
    {
        std::cin >> val;
        vec.push_back(val);
    }
    
    for(int i = vec.size()-1; i>=0; i--)
    {
        tree.insert(vec[i]);
    }

    tree.evenTraversal();
    return 0;
}