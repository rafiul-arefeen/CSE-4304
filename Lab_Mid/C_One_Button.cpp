#include <iostream>
#include <string>

int main()
{
    char ch;
    std::string str;
    while (std::cin >> ch)
    {
        if (ch == '<')
        {
            if (!str.empty())
                str.pop_back();
        }
        else
            str.push_back(ch);
    }

    std::cout << str;

    return 0;
}