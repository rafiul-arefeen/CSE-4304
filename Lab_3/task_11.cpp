#include <iostream>
#include <vector>
#include <stack>

int main()
{
    int n1, n2, x;
    std::stack<int> container;
    std::stack<int> temp;
    std::vector<int> shuttles;
    std::vector<int> target;

    std::cin >> n1 >> n2;

    for (int i = 0; i < n1; i++)
    {
        std::cin >> x;
        shuttles.push_back(x);
    }
    for (int i = 0; i < n2; i++)
    {
        std::cin >> x;
        target.push_back(x);
    }
    for (int i = n1 - 1; i >= 0; i--)
    {
        container.push(shuttles[i]);
    }

    for (int i = 0; i < n2; i++)
    {
        while (container.top() != target[i])
        {
            temp.push(container.top());
            container.pop();
        }

        std::cout << temp.size() + 1 << " ";

        container.pop();
        while (!temp.empty())
        {
            container.push(temp.top());
            temp.pop();
        }
        container.push(target[i]);
    }

    return 0;
}