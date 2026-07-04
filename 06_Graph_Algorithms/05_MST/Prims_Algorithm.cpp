#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

vector<vector<pll>> graph;
vector<bool> inMST;

ll primsMST()
{
    priority_queue<pll, vector<pll>, greater<pll>> pq; // min heap to sort wight-wise
    ll mstCost = 0;
    pq.push({0, 1}); // pushing source vertex along with zero cost

    while (!pq.empty())
    {
        auto [weight, u] = pq.top();
        pq.pop();
        if (inMST[u])
            continue;
        mstCost += weight;
        inMST[u] = true;

        for (auto [v, wt] : graph[u])
        {
            if (!inMST[v])
                pq.push({wt, v});
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
        cout << "MST Cost: " << cost << endl;
}