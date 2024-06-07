#include <iostream>
#include <stack>
#include <deque>

class Node
{
public:
    int data;
    Node *parent;
    Node *left;
    Node *right;
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
            std::cout << current->data << "(" << current->height << ") ";
            inorder(current->right);
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
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            }

            if (val < parent->data)
            {
                parent->left = newNode;
                newNode->parent = parent;
            }
            else
            {
                parent->right = newNode;
                newNode->parent = parent;
            }

            int h = 1;
            current = parent;
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
    }

    void print()
    {
        inorder(root);
        std::cout << std::endl;
    }

    void findPath(int x, int y)
    {
        std::deque<int> path;
        Node *LCA = findLCA(x, y);

        Node *current = LCA;
        while (current->data != x)
        {
            path.push_front(current->data);

            if (x < current->data)
                current = current->left;
            else
                current = current->right;
        }
        path.push_front(x);

        current = LCA;
        while (current->data != y)
        {
            if (y < current->data)
                current = current->left;
            else
                current = current->right;
            path.push_back(current->data);
        }

        int size = path.size();
        while (!path.empty())
        {
            std::cout << path.front() << " ";
            path.pop_front();
        }

        std::cout << std::endl;
        std::cout << size << std::endl;
    }
};

int main()
{
    BST tree;
    int val;

    while (std::cin >> val)
    {
        if (val == -1)
            break;

        tree.insert(val);
    }

    std::cout << "Status: ";
    tree.print();

    int x, y;
    while (std::cin >> x >> y)
    {
        tree.findPath(x, y);
    }

    return 0;
}