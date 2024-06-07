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
    void inorder(Node *current)
    {
        if (current != nullptr)
        {
            inorder(current->left);

            std::cout << current->data << "(";
            current->parent == nullptr ? std::cout << "null" : std::cout << current->parent->data;
            std::cout << ") ";
            
            inorder(current->right);
        }
    }
    void preorder(Node *current)
    {
        if (current != nullptr)
        {
            std::cout << current->data << "(";
            current->parent == nullptr ? std::cout << "null" : std::cout << current->parent->data;
            std::cout << ") ";

            preorder(current->left);
            preorder(current->right);
        }
    }
    void postorder(Node *current)
    {
        if (current != nullptr)
        {
            postorder(current->left);
            postorder(current->right);
            
            std::cout << current->data << "(";
            current->parent == nullptr ? std::cout << "null" : std::cout << current->parent->data;
            std::cout << ") ";
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

    void inorderTraversal()
    {
        inorder(root);
    }

    void preorderTraversal()
    {
        preorder(root);
    }

    void postorderTraversal()
    {
        postorder(root);
    }

    void levelOrderTraversal()
    {
        int level = 1;
        if (root == nullptr)
            return;

        std::queue<Node *> queue;
        queue.push(root);

        while (!queue.empty())
        {
            std::cout << "Level: " << level << " ";

            int size = queue.size();
            for (int i = 0; i < size; ++i)
            {
                Node *current = queue.front();
                queue.pop();

                std::cout << current->data << "(";
                current->parent == nullptr ? std::cout << "null" : std::cout << current->parent->data;
                std::cout << ") ";

                if (current->left)
                    queue.push(current->left);

                if (current->right)
                    queue.push(current->right);
            }

            level++;
            std::cout << std::endl;
        }
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
    std::cout << "Inorder: " << std::endl;
    tree.inorderTraversal();
    std::cout << std::endl;

    std::cout << "Preorder: " << std::endl;
    tree.preorderTraversal();
    std::cout << std::endl;

    std::cout << "Postorder: " << std::endl;
    tree.postorderTraversal();
    std::cout << std::endl;

    tree.levelOrderTraversal();

    return 0;
}