#include <iostream>
#include <vector>
#include <algorithm>

class PriorityQueue
{
private:
    std::vector<int> arr;
    int max_size;

    void min_heapify(int idx)
    {
        int l_child = 2 * idx + 1;
        int r_child = 2 * idx + 2;
        int smallest = idx;

        if (l_child < max_size && arr[l_child] < arr[smallest])
            smallest = l_child;

        if (r_child < max_size && arr[r_child] < arr[smallest])
            smallest = r_child;

        if (smallest != idx)
        {
            std::swap(arr[idx], arr[smallest]);
            min_heapify(smallest);
        }
    }

public:
    PriorityQueue(std::vector<int> &vec) : arr(vec), max_size(vec.size()) {}

    void build_heap()
    {
        for (int i = max_size / 2 - 1; i >= 0; i--)
        {
            min_heapify(i);
        }
    }

    int heap_minimum()
    {
        return arr[0];
    }

    int heap_extract_min()
    {
        int min = arr[0];

        std::swap(arr[0], arr[max_size - 1]);
        arr.pop_back();
        max_size--;
        build_heap();

        return min;
    }

    void min_heap_insert(int val)
    {
        arr.push_back(val);
        max_size++;
        build_heap();
    }

    void heap_decrease_key(int p, int k)
    {
        arr[p - 1] -= k;
        build_heap();
    }

    void heap_increase_key(int p, int k)
    {
        arr[p - 1] += k;
        build_heap();
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
    int n, val, pos;
    std::vector<int> vec;

    while (std::cin >> n)
    {
        if (n == -1)
            break;
        vec.push_back(n);
    }

    PriorityQueue pq(vec);
    pq.build_heap();

    std::cout << "Min Heap: ";
    pq.display();

    while (std::cin >> n)
    {
        if (n == 1)
        {
            std::cout << pq.heap_minimum() << std::endl;
            pq.display();
        }
        else if (n == 2)
        {
            std::cout << pq.heap_extract_min() << std::endl;
            pq.display();
        }
        else if (n == 3)
        {
            std::cin >> val;
            pq.min_heap_insert(val);
            pq.display();
        }
        else if (n == 4)
        {
            std::cin >> pos >> val;
            pq.heap_decrease_key(pos, val);
            pq.display();
        }
        else
        {
            std::cin >> pos >> val;
            pq.heap_increase_key(pos, val);
            pq.display();
        }
    }

    return 0;
}