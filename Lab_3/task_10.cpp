#include <iostream>
#include <stack>
#include <vector>

int main()
{
    std::stack<int> sideStreetStack;
    std::vector<int> arrivalOrder;

    int n, x;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> x;
        arrivalOrder.push_back(x);
    }

    int expectedNext = 1;

    for (int i = 0; i < n; ++i)
    {
        while (!sideStreetStack.empty() && sideStreetStack.top() == expectedNext)
        {
            sideStreetStack.pop();
            expectedNext++;
        }

        if (arrivalOrder[i] == expectedNext)
        {
            expectedNext++;
        }
        else
        {
            sideStreetStack.push(arrivalOrder[i]);
        }
    }

    while (!sideStreetStack.empty() && sideStreetStack.top() == expectedNext)
    {
        sideStreetStack.pop();
        expectedNext++;
    }

    if (sideStreetStack.empty())
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }

    return 0;
}
