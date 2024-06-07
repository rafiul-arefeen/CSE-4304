#include <iostream>
#include <vector>
#include <algorithm>

class Heap
{
private:
    std::vector<int> arr;
    int max_size;

public:
    Heap(std::vector<int> &arr, int max_size) : arr(arr), max_size(max_size) {}

    void max_heapify(int idx)
    {
        int l_child = 2 * idx + 1;
        int r_child = 2 * idx + 2;
        int largest = idx;

        if (l_child < max_size && arr[l_child] > arr[largest])
        {
            largest = l_child;
        }

        if (r_child < max_size && arr[r_child] > arr[largest])
        {
            largest = r_child;
        }

        if (largest != idx)
        {
            std::swap(arr[idx], arr[largest]);
            max_heapify(largest);
        }
    }

    void sort_heapify(int idx, int size)
    {
        int l_child = 2 * idx + 1;
        int r_child = 2 * idx + 2;
        int largest = idx;

        if (l_child < size && arr[l_child] > arr[largest])
        {
            largest = l_child;
        }

        if (r_child < size && arr[r_child] > arr[largest])
        {
            largest = r_child;
        }

        if (largest != idx)
        {
            std::swap(arr[idx], arr[largest]);
            sort_heapify(largest, size);
        }
    }

    void build_heap()
    {
        for (int i = max_size / 2 - 1; i >= 0; i--)
        {
            max_heapify(i);
        }
    }

    void heap_sort()
    {
        build_heap();
        int temp = max_size - 1;
        for (int i = temp; i >= 0; i--)
        {
            std::swap(arr[i], arr[0]);
            sort_heapify(0, i);
        }
        reverse(arr.begin(), arr.end());
    }

    void display()
    {
        for (int i = 0; i < max_size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    int n;
    std::vector<int> vec;
    std::cin >> n;

    while (n != -1)
    {
        vec.push_back(n);
        std::cin >> n;
    }

    Heap heap(vec, vec.size());

    std::cout << "Max Heap: ";
    heap.build_heap();
    heap.display();

    std::cout << "Sorted: ";
    heap.heap_sort();
    heap.display();

    return 0;
}