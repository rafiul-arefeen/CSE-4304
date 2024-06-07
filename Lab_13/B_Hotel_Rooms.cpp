#include <bits/stdc++.h>

#include <bits/stdc++.h>

class SegmentTree
{
private:
    int *segment;
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
            segment[node] = std::max(segment[left], segment[right]);
        }
    }

    int _query(int node, int b, int e, int i, int j)
    {
        if (b > j || e < i)
            return INT_MIN;
        else if (b >= i && e <= j)
            return segment[node];
        else
        {
            int left = node * 2;
            int right = node * 2 + 1;
            int mid = (b + e) / 2;
            int p1 = _query(left, b, mid, i, j);
            int p2 = _query(right, mid + 1, e, i, j);
            return std::max(p1, p2);
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
        segment[node] = std::max(segment[left], segment[right]);
    }

public:
    SegmentTree(std::vector<int> &in)
    {
        input = in;
        n = in.size();
        segment = new int[4 * n];
        init(1, 0, n - 1);
    }

    int query(int i, int j)
    {
        return _query(1, 0, n - 1, i, j);
    }
    void update(int i, int newValue)
    {
        _update(1, 0, n - 1, i, newValue);
    }
};

int main()
{
    int n, m, x;
    std::vector<int> hotel;
    hotel.push_back(0);

    std::cin >> n >> m;
    while(n--)
    {
        std::cin >> x;
        hotel.push_back(x);
    }
    
    SegmentTree st(hotel);

    while(m--)
    {
        std::cin >> x;
        std::cout << st.query() << " ";
    }

    return 0;
}