#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll INF = LLONG_MAX;
vector<ll> dist;
vector<ll> predecessor;
vector<vector<pll>> graph;

void initialize(ll v)
{
    dist.assign(v + 1, INF);
    predecessor.assign(v + 1, -1);
    graph.resize(v + 1);
}

void dijkstra_sparse(ll source)
{
    dist[source] = 0;
    set<pll> s;

    s.insert({0, source});
    while (!s.empty())
    {
        auto it = s.begin();
        pll pr = *it;

        ll weight = pr.first;
        ll node = pr.second;

        s.erase(it);

        if (weight > dist[node]) // we don't wanna process the same nodes for multiple times for those nodes who already got best values
            continue;

        for (auto x : graph[node])
        {
            ll wt = x.second;
            ll neigh = x.first;

            ll newDist = wt + weight;
            if (newDist < dist[neigh]) // Relaxation step
            {
                dist[neigh] = newDist;
                s.insert({newDist, neigh});
                predecessor[neigh] = node;
            }
        }
    }
}

vector<ll> getPath(ll source, ll destination)
{
    vector<ll> path;
    if (dist[destination] == INF)
        return path;
    for (ll i = destination; i != -1; i = predecessor[i])
    {
        path.push_back(i);
        if (i == source)
            break;
    }

    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    ll v, e;
    cin >> v >> e;

    initialize(v);

    for (int i = 1; i <= e; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    cout << "Enter Source: ";
    ll source;
    cin >> source;

    dijkstra_sparse(source);

    cout << "Shortest Distance from " << source << " to every other node: " << endl;
    for (int i = 1; i <= v; i++)
    {
        cout << i << ": " << dist[i] << endl;
    }

    cout << "Choose destination to explore shortest path : " << endl;
    ll dest;
    cin >> dest;

    vector<ll> path = getPath(source, dest);

    if (path.empty())
    {
        cout << "Unreachable" << endl;
        return 0;
    }
    else
    {
        for (auto x : path)
        {
            cout << x << " ";
        }
    }
}