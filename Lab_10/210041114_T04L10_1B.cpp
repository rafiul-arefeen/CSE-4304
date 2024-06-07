#include <iostream>
#include <string>
#include <cwctype>

const int A_S = 26;

class Trie
{
private:
    struct Node
    {
        Node *next[A_S];
        bool endmark;

        Node()
        {
            endmark = false;
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
    }

    bool search(std::string str)
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
        return curr->endmark;
    }

    int prefixSearch(std::string str)
    {
        int len = str.length();
        for (int i = 0; i < len; i++)
        {
            str[i] = towlower(str[i]);
        }

        Node *curr = root;
        int count = 0;

        for (int i = 0; i < len; i++)
        {
            int idx = str[i] - 'a';
            if (curr->next[idx] == nullptr)
                return 0;
            else
                curr = curr->next[idx];
        }

        countWords(curr, count);
        return count;
    }
};

int main()
{
    std::string str;
    int n, q;
    Trie trie;

    std::cin >> n >> q;
    while (n--)
    {
        std::cin >> str;
        trie.insert(str);
    }
    while (q--)
    {
        std::cin >> str;
        std::cout << trie.prefixSearch(str) << std::endl;
    }

    return 0;
}