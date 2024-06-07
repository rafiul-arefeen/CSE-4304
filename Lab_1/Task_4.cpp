#include <iostream>
#include <unordered_map>

int main()
{
    int n, m, k, x;
    int num1[10000], num2[10000];
    int intersection[100000];
    n = m = k = 0;

    std::unordered_map<int, int> frequency_map;

    while (std::cin >> x && x != -1)
    {
        num1[n] = x;
        n++;
        frequency_map[x]++;
    }

    while (std::cin >> x && x != -1)
    {
        num2[m] = x;
        m++;
    }

    for (int i = 0; i <= m; i++)
    {
        if (frequency_map[num2[i]] > 0)
        {
            intersection[k] = num2[i];
            frequency_map[num2[i]]--;
            k++;
        }
    }

    for (int i = 0; i < k; i++)
    {
        std::cout << intersection[i] << " ";
    }

    return 0;
}