#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dijkstra(ll source, vector<vector<pair<ll, ll>>> &vc, vector<ll> &distance)
{
    distance[source] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;

    pq.push({0, source});
    while (!pq.empty())
    {
        pair<ll, ll> pr = pq.top();
        pq.pop();

        if (pr.first > distance[pr.second])
            continue;

        for (auto x : vc[pr.second])
        {
            ll newDist = x.second + pr.first;
            if (newDist < distance[x.first])
            {
                distance[x.first] = newDist;
                pq.push({newDist, x.first});
            }
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<pair<ll, ll>>> vc(v + 1);

    for (int i = 0; i < e; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        vc[a].push_back({b, c});
    }

    vector<ll> distance(v + 1, LLONG_MAX);
    dijkstra(1, vc, distance);

    for (int i = 1; i <= v; i++)
    {
        cout << i << ": " << distance[i] << endl;
    }
}