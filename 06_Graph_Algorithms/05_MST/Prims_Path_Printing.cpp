#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

vector<vector<pll>> graph;
vector<bool> inMST;
vector<pll> mstEdges;

ll primsMST()
{
    priority_queue<tll, vector<tll>, greater<tll>> pq;
    ll mstCost = 0;
    pq.push({0, 1, -1});

    while (!pq.empty())
    {
        auto [weight, u, parent] = pq.top();
        pq.pop();
        if (inMST[u])
            continue;
        mstCost += weight;
        inMST[u] = true;
        if (parent != -1)
            mstEdges.push_back({parent, u});

        for (auto [v, wt] : graph[u])
        {
            if (!inMST[v])
                pq.push({wt, v, u});
        }
    }

    for (size_t i = 1; i < inMST.size(); i++)
    {
        if (!inMST[i])
            return -1;
    }

    return mstCost;
}

int main()
{
    ll v, e;
    cin >> v >> e;
    graph.resize(v + 1);

    for (size_t i = 1; i <= e; i++)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    inMST.resize(v + 1, false);

    ll cost = primsMST();
    if (cost == -1)
        cout << "No Possible MST !" << endl;
    else
    {
        cout << "MST Cost: " << cost << endl;
        cout << "MST Edges: " << endl;
        for (auto edges : mstEdges)
        {
            cout << edges.first << "-" << edges.second << endl;
        }
    }
}