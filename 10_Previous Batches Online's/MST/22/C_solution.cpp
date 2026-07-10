#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent, sz;

public:
    DSU(int n)
    {
        parent.resize(n);
        sz.assign(n, 1);
        for (int i = 0; i < n; i++)
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

    int N, M, P;
    cin >> N >> M >> P;

    int K;
    cin >> K;

    vector<int> risky(N, 0);

    for (int i = 0; i < K; i++)
    {
        int x;
        cin >> x;
        risky[x] = 1;
    }

    vector<tuple<int, int, int>> safeEdges;
    vector<tuple<int, int, int>> riskyEdges;

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        int penalty = (risky[u] + risky[v]) * P;
        int cost = w + penalty;

        if (!risky[u] && !risky[v])
            safeEdges.push_back({cost, u, v});
        else
            riskyEdges.push_back({cost, u, v});
    }

    sort(safeEdges.begin(), safeEdges.end());
    sort(riskyEdges.begin(), riskyEdges.end());

    DSU dsu(N);

    vector<pair<int, int>> ans;
    long long total = 0;

    for (auto [cost, u, v] : safeEdges)
    {
        if (dsu.unite(u, v))
        {
            total += cost;
            ans.push_back({u, v});
        }
    }

    int root = -1;
    bool ok = true;

    for (int i = 0; i < N; i++)
    {
        if (risky[i])
            continue;

        if (root == -1)
            root = dsu.find(i);
        else if (root != dsu.find(i))
            ok = false;
    }

    if (!ok)
    {
        for (auto [cost, u, v] : riskyEdges)
        {
            if (dsu.unite(u, v))
            {
                total += cost;
                ans.push_back({u, v});
            }
        }
    }

    root = -1;
    ok = true;

    for (int i = 0; i < N; i++)
    {
        if (risky[i])
            continue;

        if (root == -1)
            root = dsu.find(i);
        else if (root != dsu.find(i))
            ok = false;
    }

    if (!ok)
    {
        cout << -1 << '\n';
        return 0;
    }

    cout << ans.size() << '\n';

    for (auto [u, v] : ans)
        cout << u << " " << v << endl;

    cout << total << endl;
}