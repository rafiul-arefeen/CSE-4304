#include <bits/stdc++.h>

int main()
{
    int n = 0;
    int strLen, patLen;
    std::string str;
    std::string pat;
    std::string test;

    std::cin >> str >> pat;

    strLen = str.length();
    patLen = pat.length();

    for (int i = 0; i < (strLen - patLen + 2); i++)
    {
        test = str.substr(i, patLen);
        if (test == pat)
            n++;
    }

    std::cout << n;

    return 0;
}