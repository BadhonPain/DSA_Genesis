#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll> tll;
const ll INF = LLONG_MAX;

vector<tll> edge_list; // from, to, weight
vector<ll> dist;
vector<ll> predecessor;

bool Bellman_Ford(ll source, ll v)
{
    dist[source] = 0;

    for (ll i = 0; i < v - 1; i++)
    {
        bool isChanged = false;
        for (auto edge : edge_list)
        {
            ll from = get<0>(edge);
            ll to = get<1>(edge);
            ll cost = get<2>(edge);

            if (dist[from] < INF)
            {
                if (dist[to] > dist[from] + cost)
                {
                    dist[to] = dist[from] + cost;
                    predecessor[to] = from;
                    isChanged = true;
                }
            }
        }
        if (!isChanged)
            break;
    }

    for (auto edge : edge_list) // Extra pass to  detect negative cycle
    {
        ll from = get<0>(edge);
        ll to = get<1>(edge);
        ll cost = get<2>(edge);

        if (dist[from] < INF && dist[to] > dist[from] + cost)
        {
            return false;
        }
    }

    return true;
}

void getPath(ll source, ll destination)  // Constructing path
{
    if (dist[destination] == INF)
    {
        cout << "No Path from " << source << " to " << destination << endl;
        return;
    }

    vector<ll> path;

    for (ll i = destination; i != -1; i = predecessor[i])
    {
        path.push_back(i);

        if (i == source)
            break;
    }

    reverse(path.begin(), path.end());

    cout << "Path: ";
    for (auto x : path)
        cout << x << " ";

    cout << "\nTotal Cost: " << dist[destination] << endl;
}

int main()
{
    ll v, e;
    cin >> v >> e;

    dist.assign(v + 1, INF);
    predecessor.assign(v + 1, -1);

    for (ll i = 0; i < e; i++)
    {
        ll from, to, cost;
        cin >> from >> to >> cost;
        edge_list.push_back({from, to, cost});
    }

    cout << "Enter source: ";
    ll source;
    cin >> source;

    bool noNegativeCycle = Bellman_Ford(source, v);

    if (!noNegativeCycle)
    {
        cout << "Negative cycle detected! Shortest paths are undefined." << endl;
        return 0;
    }

    for (ll i = 1; i <= v; i++)
    {
        cout << i << " : ";
        if (dist[i] == INF)
            cout << "unreachable";
        else
            cout << dist[i];
        cout << endl;
    }

    cout << "\nEnter target node to explore shortest path : " << endl;
    ll target;
    cin >> target;
    getPath(source, target);
}