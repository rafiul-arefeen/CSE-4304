#include <iostream>
#include <string>
#include <cwctype>
#include <algorithm>

const int A_S = 26;

class Trie
{
private:
    struct Node
    {
        Node *next[A_S];
        bool endmark;
        int count;

        Node()
        {
            endmark = false;
            count = 0;
            next[A_S] = {nullptr};
        }
    };
    Node *root;

    void countWords(Node *node, int &count)
    {
        if (node->endmark)
            count++;
        for (int i = 0; i < A_S; i++)
        {
            if (node->next[i] != nullptr)
                countWords(node->next[i], count);
        }
    }

public:
    Trie()
    {
        root = new Node();
    }

    void insert(std::string str)
    {
        int len = str.length();
        for (int i = 0; i < len; i++)
        {
            str[i] = towlower(str[i]);
        }

        Node *curr = root;
        for (int i = 0; i < len; i++)
        {
            int idx = str[i] - 'a';
            if (curr->next[idx] == nullptr)
                curr->next[idx] = new Node();
            curr = curr->next[idx];
        }
        curr->endmark = true;
        curr->count++;
    }

    int search(std::string str)
    {
        int len = str.length();
        for (int i = 0; i < len; i++)
        {
            str[i] = towlower(str[i]);
        }

        Node *curr = root;
        for (int i = 0; i < len; i++)
        {
            int idx = str[i] - 'a';
            if (curr->next[idx] == nullptr)
                return false;
            else
                curr = curr->next[idx];
        }

        return curr->count;
    }
};

int main()
{
    std::string str;
    int n, m, count;
    char ch;
    Trie trie;

    std::cin >> n;
    while (n--)
    {
        std::cin >> str;
        std::sort(str.begin(), str.end());
        trie.insert(str);
    }

    std::cin >> m;
    while (m--)
    {
        count = 1;
        str.erase();
        while (std::cin >> ch)
        {
            if (ch == '\n')
            {
                std::sort(str.begin(), str.end());
                count *= trie.search(str);
            }
            else if (ch == ' ')
            {
                std::sort(str.begin(), str.end());
                count *= trie.search(str);
            }
            else
                str.push_back(ch);
        }
        std::cout << count << std::endl;
    }

    return 0;
}