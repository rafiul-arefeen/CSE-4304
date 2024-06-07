#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

int main()
{
    std::string line, word;
    std::unordered_map<std::string, std::string> dictionary;
    std::vector<std::string> pair;

    while (std::getline(std::cin, line))
    {
        pair.clear();

        if (line.empty())
            break;

        std::istringstream ss(line);
        while (std::getline(ss, word, ' '))
        {
            pair.push_back(word);
        }

        dictionary[pair[1]] = pair[0];
    }

    while (std::cin >> word)
    {
        if (dictionary[word] == "")
            std::cout << "eh" << std::endl;
        else
            std::cout << dictionary[word] << std::endl;
    }

    return 0;
}