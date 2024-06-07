#include <iostream>

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *parent;

    Node(int _data) : data(_data), left(nullptr), right(nullptr), parent(nullptr) {}
};

class BinaryTree
{
private:
    Node *root;

    void preorder(Node *current)
    {
        if (current != nullptr)
        {
            std::cout << current->data << "(";
            current->parent == nullptr ? std::cout << "N" : std::cout << current->parent->data;
            std::cout << ") ";

            preorder(current->left);
            preorder(current->right);
        }
    }

    int h(Node *current)
    {
        if (current == nullptr)
            return -1;

        int l_height = h(current->left);
        int r_height = h(current->right);

        return std::max(l_height, r_height) + 1;
    }

    Node *treeSearch(Node *current, int n)
    {
        if (current == nullptr || current->data == n)
            return current;

        Node *leftSearch = treeSearch(current->left, n);
        if (leftSearch)
            return leftSearch;

        Node *rightSearch = treeSearch(current->right, n);
        if (rightSearch)
            return rightSearch;

        return nullptr;
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int val, int par, int side)
    {
        Node *newNode = new Node(val);
        if (par == 0)
        {
            root = newNode;
            return;
        }
        else
        {
            Node *up = search(par);

            if (side == 1)
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

    void print()
    {
        preorder(root);
        std::cout << "(preorder)" << std::endl;
    }

    bool remove(int val)
    {
        Node *current = search(val);

        if (current == nullptr)
            return false;
        else
        {
            Node *parent = current->parent;

            if (parent == nullptr)
                root = nullptr;
            else if (parent->left == current)
                parent->left = nullptr;
            else
                parent->right = nullptr;

            delete current;
            return true;
        }
    }

    Node *search(int val)
    {
        return treeSearch(root, val);
    }

    int height()
    {
        return h(root);
    }
};

int main()
{
    int n, data, parent, side;
    BinaryTree tree;

    std::cin >> n;
    while (n--)
    {
        std::cin >> data >> parent >> side;
        tree.insert(data, parent, side);
    }
    tree.print();

    while (std::cin >> n)
    {
        if (n == 2)
        {
            std::cin >> data;
            if (tree.remove(data))
                tree.print();
            else
                std::cout << "Not present" << std::endl;
        }
        else if (n == 3)
        {
            std::cin >> data;
            Node *node = tree.search(data);

            if (node == nullptr)
                std::cout << "Not present" << std::endl;
            else
            {
                std::cout << "Present, Left(";
                node->left == nullptr ? std::cout << "null" : std::cout << node->left->data;
                std::cout << "), Right(";
                node->right == nullptr ? std::cout << "null" : std::cout << node->right->data;
                std::cout << ")" << std::endl;
            }
        }
        else
            std::cout << tree.height() << std::endl;
    }

    return 0;
}