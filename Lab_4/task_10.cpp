#include <iostream>

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node() : prev(nullptr), next(nullptr) {}
    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};

class Deque
{
private:
    Node *head;
    Node *tail;
    int dequeSize;
    void print()
    {
        Node *ptr = head;
        while (ptr != nullptr)
        {
            std::cout << ptr->data << " ";
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }

public:
    Deque() : dequeSize(0) {}
    void push_front(int x)
    {
        Node *newNode = new Node(x);
        if (dequeSize == 0)
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        dequeSize++;
        print();
    }
    void push_back(int x)
    {
        Node *newNode = new Node(x);
        if (dequeSize == 0)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        dequeSize++;
        print();
    }
    void pop_front()
    {
        if (dequeSize == 0)
            std::cout << "Cannot pop, deque is empty." << std::endl;
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        dequeSize--;
        print();
    }
    void pop_back()
    {
        if (dequeSize == 0)
            std::cout << "Cannot pop, deque is empty." << std::endl;
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        dequeSize--;
        print();
    }
    int size()
    {
        return dequeSize;
    }
};

int main()
{
    int func_id, x;
    Deque d;

    while (std::cin >> func_id)
    {
        if (func_id == 1)
        {
            std::cin >> x;
            d.push_front(x);
        }
        else if (func_id == 2)
        {
            std::cin >> x;
            d.push_back(x);
        }
        else if (func_id == 3)
        {
            d.pop_front();
        }
        else if (func_id == 4)
        {
            d.pop_back();
        }
        else if (func_id == 5)
        {
            std::cout << d.size() << std::endl;
        }
        else
        {
            break;
        }
    }
    return 0;
}