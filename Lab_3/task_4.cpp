#include <iostream>
#include <stack>

struct info
{
    int value;
    int pos;
};

int main()
{
    int result[10000];
    int num = 0;
    int x;
    std::stack<info> stack;
    info temp;

    while (std::cin >> x && x != -1)
    {
        temp.value = x;
        temp.pos = num;
        num++;

        if (stack.empty())
            stack.push(temp);
        else
        {
            while (!stack.empty() && stack.top().value < temp.value)
            {
                result[stack.top().pos] = temp.value;
                stack.pop();
            }
            stack.push(temp);
        }
    }

    while (!stack.empty())
    {
        result[stack.top().pos] = -1;
        stack.pop();
    }

    for (int i = 0; i < num; i++)
    {
        std::cout << result[i] << " ";
    }

    return 0;
}