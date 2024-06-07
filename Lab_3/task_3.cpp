#include <iostream>
#include <vector>
#include <stack>

int main()
{
    int n, x, target;
    std::vector<int> targetArray;

    while (std::cin >> x)
    {
        targetArray.push_back(x);
    }

    n = targetArray.back();
    targetArray.pop_back();
    target = 1;

    for (int i = 0; i < targetArray.size(); i++)
    {
        while (targetArray[i] != target)
        {
            std::cout << "Push Pop ";
            target++;
        }

        std::cout << "Push ";
        target++;
    }

    return 0;
}