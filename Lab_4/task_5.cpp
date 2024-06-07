#include <iostream>
#include <queue>

int countTime(std::queue<int> q, int k)
{
    int time = 0;
    int i = 0;
    int size = q.size();
    int idx;

    while (1)
    {
        idx = i % size;

        if (q.front() > 0)
        {
            q.front()--;
            time++;
        }
        if (idx == k && q.front() == 0)
            break;

        q.push(q.front());
        q.pop();

        i++;
    }

    return time;
}

int main()
{
    int x, k;
    std::queue<int> queue;

    while (std::cin >> x && x != -1)
    {
        queue.push(x);
    }
    std::cin >> k;

    std::cout << countTime(queue, k);

    return 0;
}