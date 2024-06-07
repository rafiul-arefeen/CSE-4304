#include <iostream>
#include <stack>
#include <queue>

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

    Node *successor(Node *node)
    {
        while (node->left != nullptr)
            node = node->left;
        return node;
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

    void remove(int key)
    {
        Node *current = root;
        Node *parent = nullptr;

        while (current != nullptr && current->data != key)
        {
            parent = current;
            if (key < current->data)
                current = current->left;
            else
                current = current->right;
        }

        if (current == nullptr)
            return;

        // Case 1: Node has no left child
        if (current->left == nullptr)
        {
            if (parent == nullptr)
                root = current->right;
            else if (current == parent->left)
                parent->left = current->right;
            else
                parent->right = current->right;
            delete current;
        }

        // Case 2: Node has no right child
        else if (current->right == nullptr)
        {
            if (parent == nullptr)
                root = current->left;
            else if (current == parent->left)
                parent->left = current->left;
            else
                parent->right = current->left;
            delete current;
        }

        // Case 3: Node has both left and right children
        else
        {
            Node *successorParent = current;
            Node *successor = current->right;
            while (successor->left != nullptr)
            {
                successorParent = successor;
                successor = successor->left;
            }

            current->data = successor->data;

            if (successorParent == current)
                successorParent->right = successor->right;
            else
                successorParent->left = successor->right;

            delete successor;
        }
    }

    void levelOrderTraversal()
    {
        if (root == nullptr)
            return;

        std::queue<Node *> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty())
        {
            Node *current = nodeQueue.front();
            nodeQueue.pop();

            std::cout << current->data << " ";

            if (current->left != nullptr)
                nodeQueue.push(current->left);

            if (current->right != nullptr)
                nodeQueue.push(current->right);
        }
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
        bst.remove(val);

        bst.levelOrderTraversal();
        std::cout << std::endl;
    }

    return 0;
}