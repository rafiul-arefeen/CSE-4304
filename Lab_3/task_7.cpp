#include <iostream>
#include <stack>
#include <string>

int main()
{
    int n, result, left, right;
    std::string str;
    std::stack<int> stack;

    std::cin >> n;

    while(n--)
    {
        std::cin >> str;
        
        for(int i = 0; i<str.length(); i++)
        {
            if(str[i] <= '9' && str[i] >= '0')
                stack.push(str[i] - '0');
            
            else
            {
                right = stack.top();
                stack.pop();
                left = stack.top();
                stack.pop();

                if(str[i] == '+')
                    result = left + right;
                else if(str[i] == '-')
                    result = left - right;
                else if(str[i] == '*')
                    result = left * right;
                else
                    result = left / right;
                
                stack.push(result);
            }
        }

        std::cout << result << std::endl;
    }

    return 0;
}