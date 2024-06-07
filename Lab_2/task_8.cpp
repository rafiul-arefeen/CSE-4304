#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

struct info
{
    std::string str;
    int unsort;
};

bool comparator(info info1, info info2)
{
    return info1.unsort < info2.unsort;
}

int main()
{
    int length, n;
    info temp_info;
    std::vector<info> dna;

    std::cin >> length >> n;

    while (n--)
    {
        std::cin >> temp_info.str;
        temp_info.unsort = 0;

        for (int i = 0; i < length - 1; i++)
        {
            for (int j = i + 1; j < length; j++)
            {
                if (temp_info.str[j] < temp_info.str[i])
                    temp_info.unsort++;
            }
        }

        dna.push_back(temp_info);
    }

    std::sort(dna.begin(), dna.end(), comparator);

    for (int i = 0; i < dna.size(); i++)
    {
        std::cout << dna[i].str << " " << dna[i].unsort << std::endl;
    }

    return 0;
}