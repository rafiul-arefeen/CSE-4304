#include <bits/stdc++.h>

int main()
{
    std::string word;
    while (std::cin >> word)
    {
        std::string add;

        int i = 0;
        int j = word.length() - 1;

        while (i < j)
        {
            if (word[i] == word[j])
            {
                break;
            }
            else
            {
                add.push_back(word[i]);
                i++;
            }
        }

        std::reverse(add.begin(), add.end());
        word += add;
        std::cout << word << std::endl;
    }

    return 0;
}