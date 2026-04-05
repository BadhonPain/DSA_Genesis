#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dijkstra(ll source, vector<vector<pair<ll, ll>>> &vc, vector<ll> &distance)
{
    distance[source] = 0;
    multiset<pair<ll, ll>> ms;

    ms.insert({0, source});
    while (!ms.empty())
    {
        auto it = ms.begin();
        pair<ll, ll> pr = *it;
        ms.erase(it);

        if (pr.first > distance[pr.second])
            continue;

        for (auto x : vc[pr.second])
        {
            ll newDist = x.second + pr.first;
            if (newDist < distance[x.first])
            {
                distance[x.first] = newDist;
                ms.insert({newDist, x.first});
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