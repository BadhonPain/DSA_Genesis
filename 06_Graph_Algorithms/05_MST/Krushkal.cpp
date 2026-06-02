#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll find_parent(ll node, vector<ll> &parent)
{
    if (node == parent[node])
        return node;
    return parent[node] = find_parent(parent[node], parent);
}

void connect(ll node1, ll node2, vector<ll> &parent, vector<ll> &rank)
{
    ll par1 = find_parent(node1, parent);
    ll par2 = find_parent(node2, parent);

    if (par1 != par2)
    {
        if (rank[par1] > rank[par2])
        {
            parent[par2] = par1;
            rank[par1] += rank[par2];
        }

        else
        {
            parent[par1] = par2;
            rank[par2] += rank[par1];
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<ll> parent(v + 1);
    vector<ll> rank(v + 1);

    for (int i = 1; i <= v; i++)
    {
        parent[i] = i;
        rank[i] = i;
    }

    vector<tuple<ll, ll, ll>> edges(e);
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edges.push_back({c, a, b});
    }

    sort(edges.begin(), edges.end());
    vector<pair<ll, ll>> minimal_edges;

    ll minimal_cost = 0;
    for (auto &x : edges)
    {
        ll weight = get<0>(x);
        ll node1 = get<1>(x);
        ll node2 = get<2>(x);
        if (find_parent(node1, parent) != find_parent(node2, parent))
        {
            connect(node1, node2, parent, rank);
            minimal_cost += weight;
            minimal_edges.push_back({node1, node2});
        }
    }

    cout << "MST cost: " << minimal_cost << endl;
    cout << "MST edges: " << endl;

    for (auto &x : minimal_edges)
    {
        cout << x.first << "-" << x.second << endl;
    }
}