#include <iostream>
#include <queue>
#include <unordered_map>

int main()
{
    std::string str;
    std::unordered_map<char, int> charMap;
    std::priority_queue<std::pair<int, char>> pq;

    std::cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        charMap[str[i]]++;
    }

    for (auto it : charMap)
    {
        pq.push(std::make_pair(it.second, it.first));
    }

    while (!pq.empty())
    {
        for (int i = 0; i < pq.top().first; i++)
        {
            std::cout << pq.top().second;
        }
        pq.pop();
    }

    return 0;
}