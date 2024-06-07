#include <iostream>

class Stack
{
private:
    int max_size;
    int *stack;
    int top_index;

public:
    // Constructor
    Stack(int size)
    {
        max_size = size;
        stack[max_size];
        top_index = -1;
    }

    // Push a new value to the stack
    bool push(int item)
    {
        if (top_index < max_size - 1)
        {
            top_index++;
            stack[top_index] = item;
            return true;
        }
        else
        {
            return false;
        }
    }

    // Removes the top item of the stack
    bool pop()
    {
        if (top_index >= 0)
        {
            top_index--;
            return true;
        }
        else
        {
            return false;
        }
    }

    // Checks if the stack is empty
    bool isEmpty()
    {
        return top_index == -1;
    }

    // Checks if the stack is full
    bool isFull()
    {
        return top_index == max_size - 1;
    }

    // Returns the size of the stack
    int size()
    {
        return top_index + 1;
    }

    // Returns the top item of the stack
    int top()
    {
        if (top_index >= 0)
        {
            return stack[top_index];
        }
        else
        {
            return -1;
        }
    }

    // Print all the elements currently in the stack
    void print()
    {
        for (int i = 0; i <= top_index; i++)
        {
            std::cout << stack[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    int func_id, max_size, item;

    std::cin >> max_size;
    Stack numStack(max_size);

    while (std::cin >> func_id && func_id != -1)
    {
        if (func_id == 1)
        {
            std::cin >> item;

            if (numStack.push(item))
                numStack.print();
            else
                std::cout << "Overflow" << std::endl;
        }

        else if (func_id == 2)
        {
            if (numStack.pop())
                numStack.print();
            else
                std::cout << "Underflow" << std::endl;
        }

        else if (func_id == 3)
        {
            if (numStack.isEmpty())
                std::cout << "True" << std::endl;
            else
                std::cout << "False" << std::endl;
        }

        else if (func_id == 4)
        {
            if (numStack.isFull())
                std::cout << "True" << std::endl;
            else
                std::cout << "False" << std::endl;
        }

        else if (func_id == 5)
        {
            std::cout << numStack.size() << std::endl;
        }

        else
        {
            std::cout << numStack.top() << std::endl;
        }
    }

    return 0;
}