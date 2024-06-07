#include <iostream>
#include <queue>

int noLunch(std::queue<int> students, std::queue<int> sandwich)
{
    int n = 0;

    while (1)
    {
        if (n > students.size() || students.size() == 0)
            break;
        else if (students.front() == sandwich.front())
        {
            n = 0;
            students.pop();
            sandwich.pop();
        }
        else
        {
            n++;
            students.push(students.front());
            students.pop();
        }
    }
    std::cout << std::endl;
    return students.size();
}

int main()
{
    int n, x;
    std::queue<int> students;
    std::queue<int> sandwich;
    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> x;
        students.push(x);
    }
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> x;
        sandwich.push(x);
    }

    std::cout << noLunch(students, sandwich) << std::endl;
    return 0;
}