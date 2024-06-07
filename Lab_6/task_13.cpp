#include <iostream>
#include <queue>
#include <vector>

int main()
{
    std::priority_queue<int> left;
    std::priority_queue<int, std::vector<int>, std::greater<int>> right;

    int x, n;
    double median = 0;
    std::cin >> n;
    while (n--)
    {
        std::cin >> x;
        if (left.empty() && right.empty())
        {
            left.push(x);
            median = x;
        }
        else if (x <= median)
        {
            left.push(x);

            if (left.size() > right.size() + 1)
            {
                right.push(left.top());
                left.pop();
            }
        }
        else
        {
            right.push(x);

            if (right.size() > left.size())
            {
                left.push(right.top());
                right.pop();
            }
        }

        if (left.size() == right.size())
        {
            median = static_cast<double>(left.top() + right.top()) / 2.0;
        }
        else
        {
            median = static_cast<double>(left.top());
        }
    }

    std::cout << median << " ";

    return 0;
}
