#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

std::vector<std::string> extractWords(std::string paragraph)
{
    std::string word;
    std::istringstream ss(paragraph);
    std::vector<std::string> wordStorage;

    while (std::getline(ss, word, ' '))
    {
        while (!word.empty() && !std::isalpha(word[0]))
        {
            word = word.substr(1);
        }
        while (!word.empty() && !std::isalpha(word.back()))
        {
            word.pop_back();
        }

        if (!word.empty())
            wordStorage.push_back(word);
    }

    return wordStorage;
}

int main()
{
    std::string paragraph;
    std::getline(std::cin, paragraph);
    std::vector<std::string> words = extractWords(paragraph);

    std::unordered_map<std::string, int> wordCount;

    for (const std::string &word : words)
    {
        wordCount[word]++;
    }

    for (const auto &pair : wordCount)
    {
        if (pair.second > 1)
            std::cout << pair.first << " " << pair.second << std::endl;
    }

    return 0;
}
