#include <iostream>
#include <string>
#include <stack>

bool mathCheck(std::string line)
{
    std::stack<char> stack;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == '(' || line[i] == '{' || line[i] == '[')
            stack.push(line[i]);
        else if (!stack.empty())
        {
            if (line[i] == ')')
            {
                if (stack.top() == '(')
                    stack.pop();
                else
                    return false;
            }
            else if (line[i] == '}')
            {
                if (stack.top() == '{')
                    stack.pop();
                else
                    return false;
            }
            else if (line[i] == ']')
            {
                if (stack.top() == '[')
                    stack.pop();
                else
                    return false;
            }
            else
                continue;
        }

        else if (stack.empty() && (line[i] == ')' || line[i] == '}') || line[i] == ']')
            return false;
        else
            continue;
    }

    if (stack.empty())
        return true;
    else
        return false;
}

int main()
{
    int n;
    std::string line;

    std::cin >> n;
    std::cin.ignore();

    while (n--)
    {
        std::getline(std::cin, line);

        if (mathCheck(line))
            std::cout << "Yes" << std::endl;
        else
            std::cout << "No" << std::endl;
    }

    return 0;
}