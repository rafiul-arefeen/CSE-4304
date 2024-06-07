#include <iostream>
#include <queue>
#include <vector>

int main()
{
    int z;
    std::priority_queue<int, std::vector<int>> pq;

    while (std::cin >> z && z != -1)
    {
        pq.push(z);
    }

    while (pq.size() > 1)
    {
        int y = pq.top();
        pq.pop();
        int x = pq.top();
        pq.pop();

        if (x != y)
        {
            y -= x;
            pq.push(y);
        }
    }

    if (pq.size())
        std::cout << pq.top() << std::endl;
    else
        std::cout << "0" << std::endl;
    return 0;
}