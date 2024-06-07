#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

int main()
{
    int val, target;

    std::vector<int> vec;
    std::set<std::pair<int, int>> foundPair;

    std::unordered_map<int, int> map;
    std::unordered_map<int, int> validPairMap;

    while (std::cin >> val)
    {
        if (val == -1)
            break;
        vec.push_back(val);
    }
    std::cin >> target;

    for (int i = 0; i < vec.size(); i++)
    {
        map.insert(std::make_pair(target - vec[i], vec[i]));
    }

    for (int i = 0; i < vec.size(); i++)
    {
        if (map[vec[i]] + vec[i] == target && validPairMap[vec[i]] != map[vec[i]])
        {
            std::pair<int, int> pair = {vec[i], map[vec[i]]};
            foundPair.insert(pair);
            validPairMap.insert(std::make_pair(target - vec[i], vec[i]));
        }
    }

    if (foundPair.empty())
    {
        std::cout << "No pairs found\n";
    }
    else
    {
        for (const auto &pair : foundPair)
        {
            std::cout << "(" << pair.first << ", " << pair.second;
            pair == *foundPair.rbegin() ? std::cout << ")" : std::cout << "), ";
        }
    }

    return 0;
}