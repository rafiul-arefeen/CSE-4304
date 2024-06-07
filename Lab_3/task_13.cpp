#include <iostream>
#include <stack>
#include <string>

int main()
{
    int n;
    std::string str;
    std::stack<char> stack;

    std::cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (stack.empty())
            stack.push(str[i]);
        else
        {
            if (stack.top() == '(' && str[i] == ')')
                stack.pop();
            else
                stack.push(str[i]);
        }
    }

    std::cout << str.length() - stack.size() << std::endl;

    return 0;
}