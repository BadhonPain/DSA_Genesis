#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll> tll;
typedef pair<ll, ll> pll;

vector<tll> edges;
vector<ll> tree_id;
vector<pll> mstEdges;

ll explicit_tree_id(ll vertex)
{
    // for(auto i: tree_id) cout<<i<<" ";
    if (vertex == tree_id[vertex])
        return vertex;
    return tree_id[vertex] = explicit_tree_id(tree_id[vertex]);
}

int main()
{
    ll v, e;
    cin >> v >> e;

    tree_id.resize(v + 1);
    for (size_t i = 1; i <= v; i++)
    {
        tree_id[i] = i;
    }

    for (size_t i = 1; i <= e; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        edges.push_back({weight, from, to});
    }

    sort(edges.begin(), edges.end());

    // for(auto[w,f,t] : edges) cout<<f<<" - "<<t<<" ("<<w<<")"<<endl;
    // for(auto id : tree_id) cout<<id<<" ";

    ll mstCost = 0;

    for (auto &[weight, from, to] : edges)
    {
        ll rootFrom = explicit_tree_id(from);
        ll rootTo = explicit_tree_id(to);
        if (rootFrom != rootTo)
        {
            mstCost += weight;
            mstEdges.push_back({from, to});

            tree_id[rootTo] = rootFrom;
        }
    }

    if (mstEdges.size() != v - 1)
    {
        cout << "No Possible MST !";
        return 0;
    }

    cout << "MST Cost: " << mstCost << endl;
    cout << "MST Edges: " << endl;
    for (auto &[from, to] : mstEdges)
    {
        cout << from << " - " << to << endl;
    }
}