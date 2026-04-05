#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll find_parent(ll node, vector<ll> &parent)   // FIND-SET(x)
{
    if (node == parent[node])
        return node;
    return find_parent(parent[node], parent);
}

void connect(ll node1, ll node2, vector<ll> &parent)  // UNION(x,y)
{
    ll parent_1 = find_parent(node1, parent);
    ll parent_2 = find_parent(node2, parent);

    if (parent_1 == parent_2)
        return; // already connected

    parent[parent_2] = parent_1;
    // parent[parent_1] = parent_2;  -> also fine
    
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<ll> parent(v + 1);
    for (int i = 1; i <= v; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        connect(a, b, parent);
    }

    // we can check by printing parent array that they get connected or not

    for (int i = 1; i <= v; i++)
    {
        cout << i << ": " << parent[i] << endl;
    }
}