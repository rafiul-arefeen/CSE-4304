#include <iostream>

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
    LL() : llSize(0) {}

    void insert_front(int x)
    {
        Node *newNode = new Node(x);
        if (llSize == 0)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        llSize++;
        print_head_tail();
        print();
    }

    void insert_back(int x)
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
        print_head_tail();
        print();
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
            return;
        }

        if (ptr == tail)
        {
            insert_back(x);
            llSize++;
            return;
        }
        else
        {
            newNode->next = ptr->next;
            ptr->next = newNode;
            llSize++;
        }

        print_head_tail();
        print();
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
    }

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

        print_head_tail();
        print();
    }

    void remove_element(int v)
    {
        Node *ptr = head;

        if (ptr == nullptr)
        {
            std::cout << "Value not found" << std::endl;
            print_head_tail();
            print();
            return;
        }

        if (ptr->data == v)
        {
            remove_head();
            return;
        }

        while (ptr->next != nullptr && ptr->next->data != v)
        {
            ptr = ptr->next;
        }

        if (ptr->next != nullptr)
        {
            Node *ptr2 = ptr->next;
            ptr->next = ptr->next->next;
            delete ptr2;
        }
        else
        {
            std::cout << "Value not found" << std::endl;
        }
        print_head_tail();
        print();
    }

    void remove_end()
    {
        if (llSize == 0)
        {
            std::cout << "Underflow" << std::endl;
            print_head_tail();
            print();
            return;
        }
        else if (llSize == 1)
        {
            delete tail;
            head = tail = nullptr;
            llSize--;
            print_head_tail();
            print();
            return;
        }

        Node *ptr = head;
        while (ptr->next->next != nullptr)
        {
            ptr = ptr->next;
        }

        delete ptr->next;
        ptr->next = nullptr;
        tail = ptr;
        llSize--;

        print_head_tail();
        print();
    }

    ~LL()
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
    LL dll;
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
