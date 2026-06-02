#include <bits/stdc++.h>

using namespace std;

using ll = long long;
typedef pair<ll, ll> pll;

void prim_MST(ll source, vector<vector<pll>> &edges, vector<pll> &mst_edges, ll &cost, vector<bool> &alreadyInMST)

{

    priority_queue<pll, vector<pll>, greater<pll>> pq;

    vector<ll> parent(edges.size(), -1);

    parent[source] = -1;

    pq.push({0, source});

    while (!pq.empty())

    {

        auto it = pq.top();

        pq.pop();

        ll u = it.second;

        if (alreadyInMST[u])

            continue;

        alreadyInMST[u] = true;

        cost += it.first;

        if (parent[u] != -1)

            mst_edges.push_back({parent[u], u});

        for (auto &x : edges[u])

        {

            if (!alreadyInMST[x.first])

            {

                pq.push({x.second, x.first});

                parent[x.first] = u;
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

    for (int i = 1; i <= v; i++)
    {
        prim_MST(i, edges, mst_edges, mstCost, alreadyInMST);
    }

    cout << "MST cost: " << mstCost << endl;

    cout << "MST Edges: " << endl;

    for (int i = 0; i < mst_edges.size(); i++)

    {

        cout << mst_edges[i].first << "-" << mst_edges[i].second << endl;
    }
}