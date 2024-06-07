#include <bits/stdc++.h>

class Node
{
public:
    int data;
    Node *next;
    Node() : next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
};

class LL
{
private:
    Node *head;
    Node *tail;
    int llSize;

    void remove_head()
    {
        if (llSize == 0)
        {
            std::cout << "Underflow" << std::endl;
        }
        else if (llSize == 1)
        {
            delete head;
            head = tail = nullptr;
            llSize--;
        }
        else
        {
            head = head->next;
            llSize--;
        }
    }

    Node *goToIndex(int idx)
    {
        idx--;
        Node *ptr = head;
        int pos = 1;

        while (pos != idx)
        {
            ptr = ptr->next;
            pos++;
        }

        return ptr;
    }

public:
    LL() : llSize(0) {}

    void push_back(int x)
    {
        Node *newNode = new Node(x);
        if (llSize == 0)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        llSize++;
    }

    int removeAtIndex(int idx)
    {
        int val;

        if (idx == 1)
        {
            val = head->data;
            remove_head();
            return val;
        }
        else
        {
            Node *ptr = goToIndex(idx);
            val = ptr->next->data;

            Node *ptr2 = ptr->next;
            ptr->next = ptr->next->next;
            delete ptr2;

            llSize--;
            return val;
        }
    }
};

int main()
{
    int n, x;
    LL list;

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> x;
        list.push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        std::cin >> x;
        std::cout << list.removeAtIndex(x) << " ";
    }

    return 0;
}