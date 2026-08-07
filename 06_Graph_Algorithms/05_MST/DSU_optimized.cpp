#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll find_parent(ll node, vector<ll> &parent) // FIND-SET(x) in CLRS
{
    if (node == parent[node])
        return node;
    return parent[node] = find_parent(parent[node], parent);
}

void union_by_size(ll node1, ll node2, vector<ll> &parent, vector<ll> &sz)
{ // UNION(x,y) in CLRS
    ll parent_1 = find_parent(node1, parent);
    ll parent_2 = find_parent(node2, parent);

    if (parent_1 != parent_2)
    {
        if (sz[parent_1] > sz[parent_2])
        {
            parent[parent_2] = parent_1;
            sz[parent_1] += sz[parent_2];
        }
        else
        {
            parent[parent_1] = parent_2;
            sz[parent_2] += sz[parent_1];
        }
    }
}

void union_by_rank(ll node1, ll node2, vector<ll> &parent, vector<ll> &rank)
{
    ll parent_1 = find_parent(node1, parent);
    ll parent_2 = find_parent(node2, parent);

    if (parent_1 != parent_2)
    {
        if (rank[parent_1] > rank[parent_2])
            parent[parent_2] = parent_1;
        else if (rank[parent_1] < rank[parent_2])
            parent[parent_1] = parent_2;
        else
        {
            parent[parent_1] = parent_2;
            rank[parent_2]++;
            // parent[parent_2] = parent_1;  Also fine
            // rank[parent_1] ++;
        }
    }
}

int main()
{
    ll v, e;
    cin >> v >> e;

    vector<ll> parent(v + 1);
    vector<ll> rank(v + 1, 0);
    vector<ll> sz(v + 1, 1); // size of the components

    for (ll i = 1; i <= v; i++) // MAKE_SET(x) in CLRS
        parent[i] = i;

    for (ll i = 0; i < e; i++)
    {
        ll a, b;
        cin >> a >> b;
        union_by_size(a, b, parent, sz);
        // union_by_rank(a, b, parent, rank);
    }

    // every node will print its ultimate root
    for (ll i = 1; i <= v; i++)
    {
        cout << i << ": " << find_parent(i, parent) << '\n';
    }
}