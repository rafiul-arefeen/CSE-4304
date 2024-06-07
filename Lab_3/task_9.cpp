#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

int main()
{
    std::string given;
    std::string result;
    std::stack<char> stack;

    std::cin >> given;

    for (int i = 0; i < given.length(); i++)
    {
        if (stack.empty())
            stack.push(given[i]);

        else
        {
            if (given[i] == stack.top())
                stack.pop();
            else
                stack.push(given[i]);
        }
    }

    while (!stack.empty())
    {
        result.push_back(stack.top());
        stack.pop();
    }

    std::reverse(result.begin(), result.end());

    if (result.empty())
        std::cout << "Null";
    else
        std::cout << result;

    return 0;
}