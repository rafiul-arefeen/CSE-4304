#include <iostream>
#include <string>
#include <deque>

bool prediction(std::string S, std::string T)
{
    std::deque<char> qS, qT;
    char temp;

    for (int i = 0; i < S.length(); i++)
    {
        qS.push_back(S[i]);
    }
    for (int i = 0; i < T.length(); i++)
    {
        qT.push_back(T[i]);
    }

    for (int i = 0; i < T.length(); i++)
    {
        if (qS == qT)
            return true;

        temp = qT.back();
        qT.pop_back();
        qT.push_front(temp);
    }
    return false;
}

int main()
{
    std::string S, T;
    std::cin >> S >> T;

    if (S.length() != T.length())
        std::cout << "No" << std::endl;
    else
    {
        if (prediction(S, T))
            std::cout << "Yes" << std::endl;
        else
            std::cout << "No" << std::endl;
    }

    return 0;
}