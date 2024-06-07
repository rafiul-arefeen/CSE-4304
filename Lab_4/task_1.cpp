#include <iostream>

class circularQueue
{
private:
    int size;
    int maxQ;
    int front;
    int rear;
    int *queue;

public:
    circularQueue(int x) : maxQ(x), size(0), front(0), rear(0)
    {
        queue = new int[maxQ];
    }
    ~circularQueue()
    {
        std::cout << "Exit" << std::endl;
        delete[] queue;
    }
    void enQueue(int x)
    {
        if (size == maxQ)
            std::cout << "Overflow";
        else
        {
            queue[rear] = x;
            rear = (rear + 1) % maxQ;
            size++;
            print();
        }
    }
    void deQueue()
    {
        if (size == 0)
            std::cout << "Underflow";
        else
        {
            front = (front + 1) % maxQ;
            size--;
            print();
        }
    }
    bool isEmpty()
    {
        return size == 0;
    }
    bool isFull()
    {
        return size == maxQ;
    }
    int Size()
    {
        return size;
    }
    int Front()
    {
        return queue[front];
    }
    void print()
    {
        int idx = front;
        for (int i = 0; i < size; i++)
        {
            int a = idx % maxQ;
            std::cout << queue[a] << " ";
            idx++;
        }
    }
};

int main()
{
    int func_id, max_size, x;
    std::cin >> max_size;
    circularQueue cQ(max_size);

    while (std::cin >> func_id && func_id != -1)
    {
        switch (func_id)
        {
        case 1:
        {
            std::cin >> x;
            std::cout << "EnQueue: ";
            cQ.enQueue(x);
            std::cout << std::endl;
        }
        break;
        case 2:
        {
            std::cout << "DeQueue: ";
            cQ.deQueue();
            std::cout << std::endl;
        }
        break;
        case 3:
        {
            std::cout << "isEmpty: ";
            if (cQ.isEmpty())
                std::cout << "True" << std::endl;
            else
                std::cout << "False" << std::endl;
        }
        break;
        case 4:
        {
            std::cout << "isFull: ";
            if (cQ.isFull())
                std::cout << "True" << std::endl;
            else
                std::cout << "False" << std::endl;
        }
        break;
        case 5:
        {
            std::cout << "Size: " << cQ.Size() << std::endl;
        }
        break;
        case 6:
        {
            std::cout << "Front: " << cQ.Front() << std::endl;
        }
        break;
        default:
            break;
        }
    }
}