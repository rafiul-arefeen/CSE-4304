#include <iostream>

int Iterative_binary_search(int x, int array[], int left, int right)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (array[mid] == x)
            return mid;

        if (array[mid] < x)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}

int Recursive_binary_search(int x, int array[], int left, int right)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (array[mid] == x)
            return mid;

        if (array[mid] > x)
            return Recursive_binary_search(x, array, left, mid - 1);

        return Recursive_binary_search(x, array, mid + 1, right);
    }

    return -1;
}

int main()
{
    int arr[100000];
    int x, i, target;
    i = 0;

    while(std::cin >> x && x >= 0)
    {
        arr[i] = x;
        i++;
    }

    std::cin >> target;

    std::cout << Iterative_binary_search(target, arr, 0, i) << " (using iteration)" << std::endl;
    std::cout << Recursive_binary_search(target, arr, 0, i) << " (using recursion)" << std::endl;

    return 0;
}