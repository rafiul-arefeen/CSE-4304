#include <iostream>
#include <stack>

class Node
{
public:
    int data;
    Node* parent;
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
            std::cout << current->data << " ";
            inorder(current->right);
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
            while(current != nullptr)
            {
                if(current->height > h)
                    break;
                
                if(current->height < h)
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

    Node *search(int val)
    {
        Node *current = root;

        while (current != nullptr && current->data != val)
        {
            if (val < current->data)
                current = current->left;
            else
                current = current->right;
        }

        return current;
    }

    int height(int val)
    {
        Node *current = search(val);

        if (current != nullptr)
            return current->height;
        else
            return -1;
    }

    void beforeAfter(int val)
    {
        
    }
};

int main()
{
    BST tree;
    int n, val, func;

    std::cin >> n;
    while (n--)
    {
        std::cin >> val;
        tree.insert(val);
    }
    tree.print();
    while (std::cin >> func)
    {
        if (func == 1)
        {
            std::cin >> val;
            tree.insert(val);
        }
        else if (func == 2)
        {
            tree.print();
        }
        else if (func == 3)
        {
            std::cin >> val;
            Node *node = tree.search(val);
            if (node != nullptr)
            {
                std::cout << "Present" << std::endl;

                std::cout << "Parent(";
                node->parent == nullptr ? std::cout << "null" : std::cout << node->parent->data;
                std::cout << "), ";

                std::cout << "Left(";
                node->left == nullptr ? std::cout << "null" : std::cout << node->left->data;
                std::cout << "), ";

                std::cout << "Right(";
                node->right == nullptr ? std::cout << "null" : std::cout << node->right->data;
                std::cout << ")" << std::endl;
            }
            else
                std::cout << "Not Present" << std::endl;
        }
        else if(func == 4)
        {
            std::cin >> val;
            std::cout << tree.height(val) << std::endl;
        }
        else
        {

        }
    }

    return 0;
}