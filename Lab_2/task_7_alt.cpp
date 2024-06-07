#include <iostream>
#include <vector>

struct info
{
    int mark;
    std::string grade;
};

int binarySearchLowerBound(std::vector<info> &grader, int obtained_mark)
{
    int mid;
    int left = 0;
    int right = grader.size() - 1;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (grader[mid].mark == obtained_mark)
            return mid;
        else if (grader[mid].mark < obtained_mark)
            left = mid + 1;
        else
            right = mid - 1;
    }

    if (grader[mid].mark > obtained_mark && mid != 0)
        return mid - 1;
    else
        return mid;
}

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

        int res = binarySearchLowerBound(grader, obtained_mark);
        std::cout << grader[res].grade << std::endl;
    }

    return 0;
}