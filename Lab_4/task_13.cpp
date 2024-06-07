#include <iostream>
#include <deque>

void burnEm(int n)
{
    std::deque<int> cards;

    for(int i = 1; i<=n; i++)
    {
        cards.push_back(i);
    }

    std::cout << "Discarded cards: ";
    while(cards.size() != 2)
    {
        std::cout << cards.front() << ", ";
        cards.pop_front();
        cards.push_back(cards.front());
        cards.pop_front();
    }
    std::cout << cards.front() << std::endl;
    cards.pop_front();
    std::cout << "Remaining card: " << cards.front() << std::endl;
    cards.clear();
}

int main()
{
    int n;
    while(std::cin >> n && n!=0)
    {
        burnEm(n);
    }
    return 0;
}
