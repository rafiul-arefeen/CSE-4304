#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct info
{
    int mark;
    std::string grade;
};

int main()
{
    int obtained_mark, levels, trials;
    info temp_info;
    std::vector<info> grader;

    std::cin >> levels >> trials;

    while (levels--)
    {
        std::cin >> temp_info.mark >> temp_info.grade;
        grader.push_back(temp_info);
    }

    while (trials--)
    {
        std::cin >> obtained_mark;

        if (obtained_mark >= grader[grader.size() - 1].mark)
            std::cout << grader[grader.size() - 1].grade << std::endl;
        else
        {
            for (int i = 0; i < grader.size() - 1; i++)
            {
                if (grader[i + 1].mark > obtained_mark)
                {
                    std::cout << grader[i].grade << std::endl;
                    break;
                }
            }
        }
    }

    return 0;
}