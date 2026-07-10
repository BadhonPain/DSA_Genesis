#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v;
    double w;
    bool operator<(const Edge &other) const
    {
        return w < other.w;
    }
};

class DSU
{
    vector<int> parent, sz;

public:
    DSU(int n)
    {
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

int main()
{

    int n;
    double r;
    cin >> n >> r;

    vector<pair<int, int>> city(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> city[i].first >> city[i].second;

    vector<Edge> edges;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            double dx = city[i].first - city[j].first;
            double dy = city[i].second - city[j].second;
            double d = sqrt(dx * dx + dy * dy);
            edges.push_back({i, j, d});
        }
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);

    double road = 0, rail = 0;
    int states = 1;

    for (auto &e : edges)
    {
        if (dsu.unite(e.u, e.v))
        {
            if (e.w <= r)
                road += e.w;
            else
            {
                rail += e.w;
                states++;
            }
        }
    }

    cout << states << " " << (int)round(road) << " " << (int)round(rail) << "\n";

    return 0;
}