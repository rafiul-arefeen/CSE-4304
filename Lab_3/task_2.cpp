#include <iostream>
#include <vector>
#include <string>
#include <stack>

void htmlChecker(std::vector<std::string> htmlCode, int num_of_line)
{
    std::stack<std::string> stack;
    std::string data, tag;

    for (int i = 0; i < num_of_line; i++)
    {
        int pos = 0;
        data = htmlCode[i];
        while (pos < data.length())
        {
            tag.erase();
            if (data[pos] == '<')
            {
                while (data[pos] != '>')
                {
                    tag.push_back(data[pos]);
                    pos++;
                }
                tag.push_back('>');
                if (tag[1] == '/')
                {
                    tag.erase(1, 1);
                    if (tag == stack.top())
                        stack.pop();
                    else
                    {
                        std::cout << "Error at line " << i + 1;
                        return;
                    }
                }
                else
                    stack.push(tag);
            }
            pos++;
        }
    }

    if (stack.empty())
        std::cout << "No error";
    else
        std::cout << "Error at line " << num_of_line;
}

int main()
{
    std::vector<std::string> htmlCode;
    std::string temp;
    int num_of_line, x;

    std::cin >> num_of_line;
    std::cin.ignore();

    for (int i = 0; i < num_of_line; i++)
    {
        std::getline(std::cin, temp);
        htmlCode.push_back(temp);
    }
    std::cin >> x;

    htmlChecker(htmlCode, num_of_line);

    return 0;
}