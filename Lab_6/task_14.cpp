#include <iostream>
#include <queue>
#include <vector>

int main()
{
    int n, x;
    std::priority_queue<int, std::vector<int>> pq;
    std::vector<int> vec;

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        int res = 1;
        std::cin >> x;
        pq.push(x);

        if (i >= 2)
        {
            for (int i = 0; i < 3; i++)
            {
                res *= pq.top();
                vec.push_back(pq.top());
                pq.pop();
            }
            for (int i = 0; i < 3; i++)
            {
                pq.push(vec.back());
                vec.pop_back();
            }
        }
        else
            res = -1;

        std::cout << res << std::endl;
    }
    return 0;
}