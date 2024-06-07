#include <bits/stdc++.h>

const int A_S = 10;

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
            for (int i = 0; i < A_S; ++i)
                next[i] = nullptr;
        }
    };
    bool flag;
    Node *root;

public:
    Trie() : flag(false)
    {
        root = new Node();
    }

    void insert(std::string str)
    {
        int len = str.length();

        Node *curr = root;
        for (int i = 0; i < len; i++)
        {
            int idx = str[i] - '0';

            if (curr->endmark)
                flag = true;

            if (curr->next[idx] == nullptr)
                curr->next[idx] = new Node();

            curr = curr->next[idx];
        }
        curr->endmark = true;
    }

    bool getStatus()
    {
        return flag;
    }
};

int main()
{
    int t, n, tt;
    std::string str;

    std::cin >> t;
    tt = 0;

    while (t--)
    {
        tt++;
        Trie tr;

        std::cin >> n;
        while (n--)
        {
            str.clear();
            std::cin >> str;

            tr.insert(str);
        }

        if (tr.getStatus())
            std::cout << "Case " << tt << ": NO\n";
        else
            std::cout << "Case " << tt << ": YES\n";
    }

    return 0;
}
