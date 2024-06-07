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

class DLL
{
private:
    Node *head;
    Node *tail;
    int dllSize;

    void print()
    {
        if (head == nullptr && tail == nullptr)
            std::cout << "Empty";
        else
        {
            Node *ptr = head;
            while (ptr != nullptr)
            {
                std::cout << ptr->data << " ";
                ptr = ptr->next;
            }
        }
        std::cout << std::endl;
    }

    void print_reverse()
    {
        if (head == nullptr && tail == nullptr)
            std::cout << "Empty";
        else
        {
            Node *ptr = tail;
            while (ptr != nullptr)
            {
                std::cout << ptr->data << " ";
                ptr = ptr->prev;
            }
        }
        std::cout << std::endl;
    }

    void print_head_tail()
    {
        std::cout << "Head=";
        if (head == nullptr)
            std::cout << "Null, ";
        else
            std::cout << head->data << ", ";
        std::cout << "Tail=";
        if (tail == nullptr)
            std::cout << "Null, ";
        else
            std::cout << tail->data << ", ";
    }

public:
    DLL() : head(nullptr), tail(nullptr), dllSize(0) {}

    void insert_front(int x)
    {
        Node *newNode = new Node(x);
        if (dllSize == 0)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            if (head)
                head->prev = newNode;
            head = newNode;
        }
        dllSize++;
        print_head_tail();
        print();
        print_reverse();
    }

    void insert_back(int x)
    {
        Node *newNode = new Node(x);
        if (dllSize == 0)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            if (tail)
                tail->next = newNode;
            tail = newNode;
        }
        dllSize++;
        print_head_tail();
        print();
        print_reverse();
    }

    void insert_after_node(int x, int v)
    {
        Node *newNode = new Node(x);
        Node *ptr = head;

        while (ptr != nullptr && ptr->data != v)
            ptr = ptr->next;

        if (ptr == nullptr)
        {
            std::cout << "Value Not Found" << std::endl;
            print_head_tail();
            print();
            print_reverse();
            return;
        }

        if (ptr == tail)
        {
            insert_back(x);
            dllSize++;
            return;
        }
        else
        {
            ptr->next->prev = newNode;
            newNode->next = ptr->next;

            ptr->next = newNode;
            newNode->prev = ptr;
        }
        dllSize++;
        print_head_tail();
        print();
        print_reverse();
    }

    void update_node(int x, int v)
    {
        Node *ptr = head;

        while (ptr != nullptr && ptr->data != v)
            ptr = ptr->next;

        if (ptr == nullptr)
            std::cout << "Value not found" << std::endl;
        else
            ptr->data = x;

        print_head_tail();
        print();
        print_reverse();
    }

    void remove_head()
    {
        if (dllSize == 0)
        {
            std::cout << "Underflow" << std::endl;
        }
        else if (dllSize == 1)
        {
            delete head;
            head = tail = nullptr;
            dllSize--;
        }
        else
        {
            head = head->next;
            if (head)
                head->prev = nullptr;
            dllSize--;
        }

        print_head_tail();
        print();
        print_reverse();
    }

    void remove_element(int v)
    {
        Node *ptr = head;

        while (ptr != nullptr && ptr->data != v)
            ptr = ptr->next;

        if (ptr == nullptr)
        {
            std::cout << "Value not found" << std::endl;
            print_head_tail();
            print();
            print_reverse();
            return;
        }
        else if (ptr == head)
        {
            remove_head();
            print_head_tail();
            print();
            print_reverse();
            return;
        }
        else if (ptr == tail)
        {
            remove_end();
            print_head_tail();
            print();
            print_reverse();
            return;
        }

        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete ptr;
        dllSize--;

        print_head_tail();
        print();
        print_reverse();
    }

    void remove_end()
    {
        if (dllSize == 0)
        {
            std::cout << "Underflow" << std::endl;
            print_head_tail();
            print();
            print_reverse();
            return;
        }
        else if (dllSize == 1)
        {
            delete tail;
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }

        dllSize--;
        print_head_tail();
        print();
        print_reverse();
    }

    ~DLL()
    {
        Node *ptr = head;
        while (ptr != nullptr)
        {
            Node *temp = ptr;
            ptr = ptr->next;
            delete temp;
        }
    }
};

int main()
{
    int f, key, val;
    DLL dll;
    while (std::cin >> f && f != 8)
    {
        if (f == 1)
        {
            std::cin >> key;
            dll.insert_front(key);
        }
        else if (f == 2)
        {
            std::cin >> key;
            dll.insert_back(key);
        }
        else if (f == 3)
        {
            std::cin >> key >> val;
            dll.insert_after_node(key, val);
        }
        else if (f == 4)
        {
            std::cin >> key >> val;
            dll.update_node(key, val);
        }
        else if (f == 5)
        {
            dll.remove_head();
        }
        else if (f == 6)
        {
            std::cin >> key;
            dll.remove_element(key);
        }
        else
        {
            dll.remove_end();
        }
    }
    return 0;
}
