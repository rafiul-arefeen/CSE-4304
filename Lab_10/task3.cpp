#include <iostream>
#include <string>

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

    void _display(Node* curr, std::string str, int level)
    {
        if(curr->endmark)
        {
            str[level] = '\0';
            std::cout << str << " ";
            str.erase();
        }

        for(int i = 0; i< A_S; i++)
        {
            if(curr->next[i] != nullptr)
            {
                str[level] = i + 'a';
                _display(curr->next[i], str, level + 1);
            }
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

    void display()
    {
        std::string word;
        _display(root, word, 0);
        std::cout << std::endl;
    }
};

int main()
{
    Trie trie;
    std::string str;

    while(std::cin >> str)
    {
        if(str == "\0")
            break;
        trie.insert(str);
    }

    trie.display();
    return 0;
}