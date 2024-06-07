#include <iostream>
#include <queue>
#include <unordered_map>

int main()
{
    std::unordered_map<int, int> numMap;
    std::priority_queue<std::pair<int, int>> pq;
    int x, n;

    while (std::cin >> x && x != -1)
    {
        numMap[x]++;
    }

    std::cin >> n;

    for (auto it : numMap)
    {
        pq.push(std::make_pair(it.second, it.first));
    }

    while (n--)
    {
        std::cout << pq.top().second << " ";
        pq.pop();
    }

    return 0;
}