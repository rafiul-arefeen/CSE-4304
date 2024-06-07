#include <iostream>
#include <string>
#include <stack>
#include <vector>

bool codeCheck(std::vector<std::string> code, int n)
{
    std::stack<char> stack;
    std::string line;

    for (int j = 0; j < n; j++)
    {
        line = code[j];
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
    std::vector<std::string> code;

    std::cin >> n;
    std::cin.ignore();

    for(int i = 0; i<n; i++)
    {
        std::getline(std::cin, line);
        code.push_back(line);
    }

    if(codeCheck(code, n))
        std::cout << "No error";
    else
        std::cout << "Error";

    return 0;
}