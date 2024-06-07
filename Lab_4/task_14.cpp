#include <iostream>
#include <unordered_map>
#include <vector>

struct data
{
    int val;
    int group;
};

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node() : prev(nullptr), next(nullptr) {}
    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};

class UnethicalQueue
{
private:
    Node *head;
    Node *tail;
    Node *arr[100] = {nullptr};
    int queueSize;
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
    Node *push_back(int x)
    {
        Node *newNode = new Node(x);
        if (queueSize == 0)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        queueSize++;
        return tail;
    }
    Node *push_middle(int x, Node *temp)
    {
        Node *newNode = new Node(x);

        temp->next->prev = newNode;
        newNode->next = temp->next;

        temp->next = newNode;
        newNode->prev = temp;

        return newNode;
    }
    void pop_front()
    {
        if (queueSize == 0)
            std::cout << "Cannot pop, UnethicalQueue is empty." << std::endl;
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        queueSize--;
    }

public:
    UnethicalQueue() : queueSize(0) {}

    void enQueue(data info)
    {
        if (arr[info.group] == nullptr || arr[info.group]->next == nullptr)
        {
            arr[info.group] = push_back(info.val);
        }
        else
        {
            arr[info.group] = push_middle(info.val, arr[info.group]);
        }
    }
    int deQueue()
    {
        int x = head->data;
        pop_front();
        return x;
    }
};

int main()
{
    UnethicalQueue uQ;
    int n, m, val;
    data person[1000];
    int person_no = 0;
    int group_no = 0;

    std::cin >> n;
    while (n--)
    {
        std::cin >> m;
        while (m--)
        {
            std::cin >> person[person_no].val;
            person[person_no].group = group_no;
            person_no++;
        }
        group_no++;
    }
}