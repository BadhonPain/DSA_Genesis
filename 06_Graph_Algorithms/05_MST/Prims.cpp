#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll,ll> pll;

void prim_MST(ll source, vector<vector<pll>> &edges, vector<pll> &mst_edges, ll &cost, vector<bool> &alreadyInMST)
{
    priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> pq;

    pq.push({0, {source, -1}});

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        ll u = it.second.first;
        ll parent = it.second.second;
        if (alreadyInMST[u])
            continue;
        alreadyInMST[u] = true;
        cost += it.first;
        if (parent != -1)
            mst_edges.push_back({parent, u});

        for (auto &x : edges[u])
        {
            ll v = x.first ; 
            if (!alreadyInMST[v])
            {
                ll weight = x.second;
                pq.push({weight, {v, u}});
            }
        }
    }
}

int main()
{
    ll v, e;
    cin >> v >> e;

    vector<vector<pll>> edges(v + 1);

    for (int i = 0; i < e; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    vector<pll> mst_edges;
    ll mstCost = 0;
    vector<bool> alreadyInMST(v + 1, false);

    for (int i = 1; i <= v; i++)  // for disconnected graph safety
    {
        if (!alreadyInMST[i])
            prim_MST(i, edges, mst_edges, mstCost, alreadyInMST);
    }

    cout << "MST cost: " << mstCost << endl;

    cout << "MST Edges: " << endl;
    for (int i = 0; i < mst_edges.size(); i++)
    {
        cout << mst_edges[i].first << "-" << mst_edges[i].second << endl;
    }
}