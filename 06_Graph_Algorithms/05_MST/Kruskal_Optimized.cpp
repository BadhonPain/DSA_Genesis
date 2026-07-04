#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
vector<ll> parent;
vector<ll> component_size;
vector<tll> edges;
vector<pll> minimal_edges;

ll find_parent(ll node)
{
    if (node == parent[node])
        return node;
    return parent[node] = find_parent(parent[node]);
}

void connect(ll node1, ll node2)
{
    ll par1 = find_parent(node1);
    ll par2 = find_parent(node2);

    if (par1 != par2)
    {
        if (component_size[par1] > component_size[par2])
        {
            parent[par2] = par1;
            component_size[par1] += component_size[par2];
        }

        else
        {
            parent[par1] = par2;
            component_size[par2] += component_size[par1];
        }
    }
}

int main()
{
    ll v, e;
    cin >> v >> e;

    parent.resize(v + 1);
    component_size.resize(v + 1);

    for (int i = 1; i <= v; i++)
    {
        parent[i] = i;
        component_size[i] = 1;
    }

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edges.push_back({c, a, b});
    }

    sort(edges.begin(), edges.end());

    ll minimal_cost = 0;
    for (auto &x : edges) // auto &[weight, node1, node2] : edges
    {
        ll weight = get<0>(x);
        ll node1 = get<1>(x);
        ll node2 = get<2>(x);
        if (find_parent(node1) != find_parent(node2))
        {
            connect(node1, node2);
            minimal_cost += weight;
            minimal_edges.push_back({node1, node2});
        }
    }

    if (minimal_edges.size() != v - 1)
    {
        cout << "No Possible MST !" << endl;
        return 0;
    }

    cout << "MST cost: " << minimal_cost << endl;
    cout << "MST edges: " << endl;

    for (auto &x : minimal_edges) // auto &[from, to] : minimal_edges
    {
        cout << x.first << " - " << x.second << endl;
    }
}