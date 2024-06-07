#include <bits/stdc++.h>

class DisjointSet
{
private:
    int *parent;
    std::vector<int> componentSize;
    int n;
    int componentCount;
    int max;

    void makeSet(int u)
    {
        parent[u] = u;
    }

    int find(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = find(parent[u]);
    }

public:
    DisjointSet(int _n) : n(_n), componentCount(_n)
    {
        parent = new int[n + 1];
        max = 1;
        componentSize.push_back(0);
        for (int i = 0; i < n; i++)
        {
            makeSet(i + 1);
            componentSize.push_back(1);
        }
    }

    void join(int u, int v)
    {
        int p1 = find(u);
        int p2 = find(v);

        if (p1 != p2)
        {
            parent[p2] = p1;
            componentCount--;
            componentSize[p1]++;
            if (max < componentSize[p1])
                max = componentSize[p1];
        }
    }

    void info()
    {
        std::cout << componentCount << " " << max << std::endl;
    }
};

int main()
{
    int n, m, x, y;
    std::cin >> n >> m;

    DisjointSet ds(n);

    while (m--)
    {
        std::cin >> x >> y;
        ds.join(x, y);
        ds.info();
    }

    return 0;
}