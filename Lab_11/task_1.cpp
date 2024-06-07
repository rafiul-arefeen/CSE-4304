#include <iostream>

const int R = 7;

class Hashing
{
protected:
    int inserted;
    int tableSize;
    int *hashTable;

    virtual int func(int i, int key) = 0;
    int hash(int key, int i)
    {
        return ((key + func(i, key)) % tableSize);
    }

public:
    Hashing() {}
    Hashing(int size) : tableSize(size), inserted(0)
    {
        hashTable = new int(tableSize);
        for (int i = 0; i < tableSize; i++)
        {
            hashTable[i] = -1;
        }
    }
    void insert(int key)
    {
        int i;
        for (i = 0; i < 6; i++)
        {
            int idx = hash(key, i);
            if (hashTable[idx] == -1)
            {
                hashTable[idx] = key;

                inserted++;
                float load_factor = static_cast<float>(inserted) / static_cast<float>(tableSize);

                std::cout << "Inserted : Index-" << idx << " (L.F=" << load_factor << ")\n";
                break;
            }
            else
                std::cout << "Collision: Index-" << idx << "\n";
        }

        if (i == 6)
            std::cout << "Input Abandoned\n";
    }
};

class LinearProbing : public Hashing
{
private:
    int func(int i, int key)
    {
        return i;
    }

public:
    LinearProbing(int size) : Hashing(size) {}
};

class QuadraticProbing : public Hashing
{
private:
    int func(int i, int key)
    {
        return (i * i);
    }

public:
    QuadraticProbing(int size) : Hashing(size) {}
};

class DoubleHashing : public Hashing
{
private:
    int hash_2(int key)
    {
        return (R - (key % R));
    }
    int func(int i, int key)
    {
        return (i * hash_2(key));
    }

public:
    DoubleHashing(int size) : Hashing(size) {}
};

int main()
{
    int choice, N, Q, val;
    std::cin >> choice >> N >> Q;

    if (choice == 1)
    {
        LinearProbing lp(N);
        while (Q--)
        {
            std::cin >> val;
            lp.insert(val);
        }
    }
    else if (choice == 2)
    {
        QuadraticProbing qp(N);
        while (Q--)
        {
            std::cin >> val;
            qp.insert(val);
        }
    }
    else
    {
        DoubleHashing dh(N);
        while (Q--)
        {
            std::cin >> val;
            dh.insert(val);
        }
    }

    return 0;
}