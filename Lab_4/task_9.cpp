#include <iostream>
#include <stack>

class Queue
{
private:
    std::stack<int> main;
    std::stack<int> sub;
    int maxQ;
    int qSize;
    void print()
    {
        std::stack<int> temp;
        while (!main.empty())
        {
            temp.push(main.top());
            main.pop();
        }
        std::cout << "Elements: ";
        if (temp.empty())
            std::cout << "Null";
        else
        {
            while (!temp.empty())
            {
                std::cout << temp.top() << " ";
                main.push(temp.top());
                temp.pop();
            }
        }
        std::cout << std::endl;
    }

public:
    Queue(int max) : maxQ(max), qSize(0) {}
    void enQueue(int x)
    {
        if (qSize == maxQ)
        {
            std::cout << "Size:" << qSize << " ";
            std::cout << "Elements: Overflow!" << std::endl;
        }
        else
        {
            qSize++;
            std::cout << "Size:" << qSize << " ";
            main.push(x);
            print();
        }
    }
    void deQueue()
    {
        if (qSize == 0)
        {
            std::cout << "Size:" << qSize << " ";
            std::cout << "Elements: Underflow!" << std::endl;
        }
        else
        {
            qSize--;
            std::cout << "Size:" << qSize << " ";
            while (!main.empty())
            {
                sub.push(main.top());
                main.pop();
            }
            sub.pop();
            while (!sub.empty())
            {
                main.push(sub.top());
                sub.pop();
            }
            print();
        }
    }
};

int main()
{
    int N, q, x, func_id;
    std::cin >> N >> q;

    Queue queue(N);

    while (q--)
    {
        std::cin >> func_id;
        if (func_id == 1)
        {
            std::cin >> x;
            queue.enQueue(x);
        }
        else
        {
            queue.deQueue();
        }
    }

    return 0;
}