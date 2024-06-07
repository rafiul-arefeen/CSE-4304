#include <iostream>
#include <vector>

// structure to store the value and their frequrrence
typedef struct _info
{
    int val;
    int freq = 0;
} info;

int main()
{
    int x, n, temp, z;
    std::vector<int> vec;
    info vec_info[100000];
    info temp_info;
    n = 0;
    z = 0;

    while (std::cin >> x && x > 0)
    {
        vec.push_back(x);
        n++;
    }

    // sorting the vector
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (vec[j] > vec[i])
            {
                temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }

    // storing the first value of the vector in the first array member of the structure
    vec_info[0].val = vec[0];
    vec_info[0].freq++;

    // storing the numerical value and their frequency in the structure
    for (int i = 1; i < n; i++)
    {
        // if we encounter a new value, advancing by one in the array and storing the value there
        if (vec[i] != vec[i - 1])
        {
            z++;
            vec_info[z].val = vec[i];
            vec_info[z].freq++;
        }
        // if it's the same value then increasing the frequency
        else
        {
            vec_info[z].freq++;
        }
    }

    // sorting the structure array in the basis of frequency
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (vec_info[j].freq > vec_info[i].freq)
            {
                temp_info = vec_info[i];
                vec_info[i] = vec_info[j];
                vec_info[j] = temp_info;
            }
        }
    }

    for (int i = 0; i <= z; i++)
    {
        std::cout << vec_info[i].val << " occurs " << vec_info[i].freq << " time";
        if (vec_info[i].freq > 1)
            std::cout << "s";

        std::cout << std::endl;
    }
    vec.clear();

    return 0;
}