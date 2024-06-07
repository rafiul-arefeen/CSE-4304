#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int n, k, x;
    int op = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        std::cin >> x;
        pq.push(x);
    }

    while (pq.top() < k)
    {
        int low1 = pq.top();
        pq.pop();
        int low2 = pq.top();
        pq.pop();

        int new_candy = low1 + (2 * low2);

        pq.push(new_candy);
        op++;
    }

    std::cout << op << std::endl;
    return 0;
}