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

    ll dummy;
    for (ll i = 0; i < v; i++)
    {
        dummy = -1;
        for (auto edge : edge_list)
        {
            ll from = get<0>(edge);
            ll to = get<1>(edge);
            ll cost = get<2>(edge);

            if (dist[from] < INF)
            {
                if (dist[to] > dist[from] + cost)
                {
                    dist[to] = max(-INF, dist[from] + cost);
                    predecessor[to] = from;
                    dummy = to;
                }
            }
        }
    }
    if (dummy == -1)
    {
        cout << "No negative cycle from " << source << endl;
        return true;
    }

    else
    {
        cout << "Negative Cycle detected !!!" << endl;
        ll y = dummy;
        for (ll i = 0; i < v; i++)
        {
            y = predecessor[y];
        }
        vector<ll> path;

        for (ll i = y;; i = predecessor[i])
        {
            path.push_back(i);
            if (i == y && ll(path.size()) > 1)
                break;
        }
        reverse(path.begin(), path.end());

        cout << "Negative Cycle: " << endl;
        for (auto x : path)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return false;
}

void getPath(ll source, ll destination) // Constructing path
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

    bool ok = Bellman_Ford(source, v);
    if (ok)
    {
        cout << "Shortest Path from " << source <<" : "<< endl;
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
}