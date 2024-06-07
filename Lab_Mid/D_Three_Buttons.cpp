#include <iostream>
#include <deque>
#include <stack>

int main()
{
    int t;
    char ch;
    std::string input;
    std::deque<char> output;

    std::cin >> t;
    std::cin.ignore();

    while (t--)
    {
        bool isAtEnd = true;
        bool isAtStart = false;
        input.erase();
        output.clear();

        std::stack<char> temp;
        std::getline(std::cin, input);

        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == ']')
            {
                isAtEnd = true;
                isAtStart = false;
            }
            else if (input[i] == '[')
            {
                isAtEnd = false;
                isAtStart = true;
            }
            else if (input[i] == '<')
            {
                if (isAtEnd && !isAtStart)
                {
                    if (!output.empty())
                        output.pop_back();
                }
                else if (!isAtEnd && !isAtStart)
                {
                    if (!temp.empty())
                        temp.pop();
                }
                else
                    continue;
            }
            else
            {
                if (isAtEnd && !isAtStart)
                {
                    while (!temp.empty())
                    {
                        output.push_front(temp.top());
                        temp.pop();
                    }
                    output.push_back(input[i]);
                }
                else if (isAtStart && !isAtEnd)
                {
                    while (!temp.empty())
                    {
                        output.push_front(temp.top());
                        temp.pop();
                    }
                    temp.push(input[i]);
                    isAtStart = false;
                }
                else
                    temp.push(input[i]);
            }
        }
        while (!temp.empty())
        {
            output.push_front(temp.top());
            temp.pop();
        }
        for (int i = 0; i < output.size(); i++)
        {
            std::cout << output[i];
        }
        std::cout << std::endl;
    }

    return 0;
}