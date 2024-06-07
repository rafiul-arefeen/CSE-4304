#include <bits/stdc++.h>

class SegmentTree
{
private:
    int *segment;
    int *lazy;
    int n;
    std::vector<int> input;

    void init(int node, int b, int e)
    {
        if (b == e)
        {
            segment[node] = input[b];
            return;
        }
        else
        {
            int left = node * 2;
            int right = node * 2 + 1;
            int mid = (b + e) / 2;
            init(left, b, mid);
            init(right, mid + 1, e);
            segment[node] = segment[left] + segment[right];
        }
    }

    int _query(int node, int b, int e, int i, int j)
    {
        if (b > j || e < i)
            return 0;
        else if (b >= i && e <= j)
            return segment[node];
        else
        {
            int left = node * 2;
            int right = node * 2 + 1;
            int mid = (b + e) / 2;
            int p1 = _query(left, b, mid, i, j);
            int p2 = _query(right, mid + 1, e, i, j);
            return p1 + p2;
        }
    }

    void _update(int node, int b, int e, int i, int newValue)
    {
        if (i > e || i < b)
            return;
        if (b >= i && e <= i)
        {
            segment[node] = newValue;
            return;
        }
        int left = node * 2;
        int right = node * 2 + 1;
        int mid = (b + e) / 2;
        _update(left, b, mid, i, newValue);
        _update(right, mid + 1, e, i, newValue);
        segment[node] = segment[left] + segment[right];
    }

    void _lazyUpdate(int node, int b, int e, int i, int j, int x)
    {
        if (lazy[node] != 0)
        {
            segment[node] += lazy[node];
            if (b != e)
            {
                lazy[node * 2] += lazy[node];
                lazy[(node * 2) + 1] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (b > j || e < i)
            return;

        if (b >= i && e <= j)
        {
            segment[node] += x;
            if (b != e)
            {
                lazy[node * 2] += x;
                lazy[(node * 2) + 1] += x;
            }
            return;
        }

        int left = node * 2;
        int right = node * 2 + 1;
        int mid = (b + e) / 2;
        _lazyUpdate(left, b, mid, i, j, x);
        _lazyUpdate(right, mid + 1, e, i, j, x);
        segment[node] = segment[left] ^ segment[right];
    }

public:
    SegmentTree(std::vector<int> &in)
    {
        input = in;
        n = in.size();
        segment = new int[4 * n];
        lazy = new int[4 * n];
        init(1, 0, n - 1);
    }

    int query(int i, int j)
    {
        return _query(1, 0, n - 1, i, j);
    }
    void update(int i, int j, int newValue)
    {
        _lazyUpdate(1, 0, n - 1, i, j, newValue);
    }
    void valueAt(int i)
    {
        update(i, i, 0);
        std::cout << query(i, i) << std::endl;
    }
};

int main()
{
    int n, q, a, b, u, k, func, x;
    std::vector<int> input;
    input.push_back(0);

    std::cin >> n >> q;
    while (n--)
    {
        std::cin >> x;
        input.push_back(x);
    }

    SegmentTree st(input);

    while (q--)
    {
        std::cin >> func;

        if (func == 1)
        {
            std::cin >> a >> b >> u;
            st.update(a, b, u);
        }
        else
        {
            std::cin >> k;
            st.valueAt(k);
        }
    }

    return 0;
}