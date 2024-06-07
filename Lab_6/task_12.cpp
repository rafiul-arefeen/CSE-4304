#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int x, n;
    

    while (std::cin >> n && n != 0)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        while (n--)
        {
            std::cin >> x;
            pq.push(x);
        }
        int cost = 0;

        while (pq.size() > 1)
        {
            int num1 = pq.top();
            pq.pop();
            int num2 = pq.top();
            pq.pop();

            int num = num1 + num2;
            cost += num;
            pq.push(num);
        }

        std::cout << cost << std::endl;
    }
    return 0;
}