#include <bits/stdc++.h>

int main()
{
    int n, x, point;
    int a_index, b_index;
    std::vector<int> a;
    std::vector<int> b;

    point = a_index = b_index = 0;

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> x;
        a.push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        std::cin >> x;
        b.push_back(x);
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    while (a_index < n)
    {
        if (a[a_index] > b[b_index])
        {
            point++;
            a_index++;
            b_index++;
        }
        else
        {
            a_index++;
        }
    }

    std::cout << point << std::endl;
    return 0;
}