#include <iostream>
#include <vector>

int main()
{
    std::vector<int> soldiers;
    int num, levels, x;

    std::cin >> num >> levels;

    for (int i = 0; i < num; i++)
    {
        std::cin >> x;
        soldiers.push_back(x);
    }

    while (levels--)
    {
        int power, kill_count, score;
        kill_count = score = 0;

        std::cin >> power;
        for (int i = 0; i < num; i++)
        {
            // for each level, iterating through powers of soldiers and checking if they can be killed
            if (power >= soldiers[i])
            {
                // updating kill count if they can be killed
                kill_count++;
                score += soldiers[i];
            }
        }

        std::cout << kill_count << " " << score << std::endl;
    }

    return 0;
}