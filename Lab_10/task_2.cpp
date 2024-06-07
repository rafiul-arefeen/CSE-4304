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

class AVL_Tree
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
        int h = 0;
        while (current != nullptr)
        {
            if (current->height > h)
                break;

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
    int height(Node *current)
    {
        return current->height;
    }
    // LL
    Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update parent pointers
    if (y->left != nullptr)
        y->left->parent = y;
    x->parent = y->parent;
    y->parent = x;
    if (T2 != nullptr)
        T2->parent = y;

    // Update heights
    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update parent pointers
    if (x->right != nullptr)
        x->right->parent = x;
    y->parent = x->parent;
    x->parent = y;
    if (T2 != nullptr)
        T2->parent = x;

    // Update heights
    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}


    void balance(Node *current, int val, int bf)
{
    if (bf > 1)
    {
        if (val < current->left->data)
        {
            current = rightRotate(current);
            if (current->parent == nullptr)
                root = current; // Update root if the current node is the new root after rotation
        }
        else
        {
            current->left = leftRotate(current->left);
            current = rightRotate(current);
            if (current->parent == nullptr)
                root = current; // Update root if the current node is the new root after rotation
        }
    }
    else if (bf < -1)
    {
        if (val > current->right->data)
        {
            current = leftRotate(current);
            if (current->parent == nullptr)
                root = current; // Update root if the current node is the new root after rotation
        }
        else
        {
            current->right = rightRotate(current->right);
            current = leftRotate(current);
            if (current->parent == nullptr)
                root = current; // Update root if the current node is the new root after rotation
        }
    }

    // Update parent pointers after rotations
    if (current->parent != nullptr)
    {
        if (current->parent->left == current)
            current->parent->left = current;
        else
            current->parent->right = current;
    }
}


public:
    AVL_Tree() : root(nullptr) {}

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

            updateHeight(newNode);

            Node *node = newNode;
            while (node != nullptr)
            {
                int bf = balanceFactor(node);
                if (bf < -1 || bf > 1)
                {
                    std::cout << "Imbalance at node: " << node->data << std::endl;
                    balance(node, val, bf);
                }
                node = node->parent;
            }
        }
    }

    void printAVL()
    {
        inorder(root);
        std::cout << std::endl;
    }
};

int main()
{
    int n;
    AVL_Tree tree;
    while (std::cin >> n)
    {
        if (n == -1)
            break;
        tree.insert(n);
        tree.printAVL();
    }
    return 0;
}