#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> pos;
    std::vector<float> val;
    int x;
    float y;

    while (std::cin >> x && x != -1)
    {
        pos.push_back(x);
    }

    for (int i = 0; i < pos.size(); i++)
    {
        std::cin >> y;
        val.push_back(y);
    }

    float arr[pos.size()];

    for (int i = 0; i < pos.size(); i++)
    {
        arr[pos[i] - 1] = val[i];
    }

    for (float Value : arr)
    {
        std::cout << Value << " ";
    }

    return 0;
}