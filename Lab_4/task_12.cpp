#include <iostream>
#include <string>
#include <deque>
#include <stack>

void breakIt(std::string str)
{
    std::deque<char> brkn;
    std::stack<char> rev;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '[')
        {
            i++;
            while ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_')
            {
                rev.push(str[i]);
                i++;
            }
            while (!rev.empty())
            {
                brkn.push_front(rev.top());
                rev.pop();
            }
            i--;
        }
        else if (str[i] == ']')
            continue;
        else
        {
            brkn.push_back(str[i]);
        }
    }

    for (int i = 0; i < brkn.size(); i++)
    {
        std::cout << brkn[i];
    }
    std::cout << std::endl;

    brkn.clear();
}

int main()
{
    std::string str;
    while (std::getline(std::cin, str, '\n'))
    {
        breakIt(str);
    }
    return 0;
}