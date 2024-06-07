#include <iostream>
#include <stack>
#include <string>

int main()
{
    int t, n;
    std::string str;
    std::stack<char> stack;

    std::cin >> t;
    while(t--)
    {
        std::cin >> n;
        std::cin >> str;

        for(int i = 0; i<n; i++)
        {
            if(stack.empty())
                stack.push(str[i]);
            else
            {
                if(stack.top() == '(' && str[i] == ')')
                    stack.pop();
                else
                    stack.push(str[i]);
            }
        }

        std::cout << stack.size() / 2 << std::endl;
    }

    return 0;
}