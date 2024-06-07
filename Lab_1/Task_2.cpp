#include <iostream>

int Factorial_using_iteration(int n)
{
    int fact = 1;

    do
    {
        fact *= n;
    } while (--n);

    return fact;
}

int Factorial_using_recursion(int n)
{
    if (n > 1)
        return n * Factorial_using_recursion(n - 1);
    else
        return 1;
}

int main()
{
    int n;

    std::cin >> n;

    std::cout << Factorial_using_iteration(n) << " (using iteration)" << std::endl;
    std::cout << Factorial_using_recursion(n) << " (using recursion)" << std::endl;

    return 0;
}