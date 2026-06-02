#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll find_parent(ll node, vector<ll> &parent) // FIND-SET(x) in CLRS
{
    if (node == parent[node])
        return node;
    return parent[node] = find_parent(parent[node], parent);
}

void connect(ll node1, ll node2, vector<ll> &parent, vector<ll> &rank)
{ // UNION(x,y) in CLRS
    ll parent_1 = find_parent(node1, parent);
    ll parent_2 = find_parent(node2, parent);

    if (parent_1 != parent_2)
    {
        if (rank[parent_1] > rank[parent_2])
        {
            parent[parent_2] = parent_1;
            rank[parent_1] += rank[parent_2];
        }
        else
        {
            parent[parent_1] = parent_2;
            rank[parent_2] += rank[parent_1];
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<ll> parent(v + 1);
    vector<ll> rank(v + 1);

    for (int i = 1; i <= v; i++) // MAKE_SET(x) in CLRS
    {
        parent[i] = i;
        rank[i] = i;
    }

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        connect(a, b, parent, rank);
    }

    // we can check by printing parent array that they get connected or not

    for (int i = 1; i <= v; i++)
    {
        cout << i << ": " << parent[i] << endl;
    }
}