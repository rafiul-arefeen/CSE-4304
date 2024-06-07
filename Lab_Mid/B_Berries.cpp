#include <bits/stdc++.h>

struct data
{
    int group;
    int upTo;
};

int main()
{
    int n, m, x;
    int sum;
    std::vector<int> tasty;
    std::vector<int> sumUp;

    std::cin >> n;
    std::cin >> x;
    sumUp.push_back(x);
    n--;

    while (n--)
    {
        std::cin >> x;
        sumUp.push_back(x + sumUp.back());
    }
    std::cin >> m;
    while (m--)
    {
        std::cin >> x;
        tasty.push_back(x);
    }

    for (int i = 0; i < tasty.size(); i++)
    {
        int res = (std::lower_bound(sumUp.begin(), sumUp.end(), tasty[i]) - sumUp.begin());

        std::cout << res + 1 << std::endl;
    }

    return 0;
}