#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll INF = LLONG_MAX;
vector<ll> best;
vector<ll> sec_best;
vector<ll> predecessor;
vector<ll> sec_best_predecessor;
vector<vector<pll>> graph;

void initialize(ll v)
{
    best.assign(v + 1, INF);
    sec_best.assign(v + 1, INF);
    predecessor.assign(v + 1, -1);
    sec_best_predecessor.assign(v + 1, -1);
    graph.assign(v + 1, {});
}

void dijkstra_sparse(ll source)
{
    best[source] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    pq.push({0, source});
    while (!pq.empty())
    {
        auto pr = pq.top();

        ll weight = pr.first;
        ll node = pr.second;

        pq.pop();

        if (weight > sec_best[node])
            continue;

        for (const auto &x : graph[node])
        {
            ll wt = x.second;
            ll neigh = x.first;

            if (weight == INF)
                continue;
            ll newDist = wt + weight;
            if (newDist < best[neigh])
            {
                sec_best[neigh] = best[neigh];
                sec_best_predecessor[neigh] = predecessor[neigh];
                if (sec_best[neigh] != INF)
                    pq.push({sec_best[neigh], neigh});
                best[neigh] = newDist;
                predecessor[neigh] = node;
                pq.push({best[neigh], neigh});
            }

            else if (newDist > best[neigh] && newDist < sec_best[neigh])
            {
                // best[neigh] remains unchanged
                sec_best[neigh] = newDist;
                pq.push({newDist, neigh});
                sec_best_predecessor[neigh] = node;
            }
        }
    }
}

vector<ll> getPath(ll source, ll destination, ll decider)
{
    vector<ll> path;

    vector<ll> &parent = (decider == 1) ? predecessor : sec_best_predecessor;
    vector<ll> &dist = (decider == 1) ? best : sec_best;

    if (dist[destination] == INF)
        return path;

    for (ll cur = destination; cur != -1; cur = parent[cur])
    {
        path.push_back(cur);

        if (cur == source)
            break;
    }

    reverse(path.begin(), path.end());

    if (path.empty() || path.front() != source)
        path.clear();

    return path;
}

void print_path(ll v, ll decider, ll source)
{
    vector<ll> &container = (decider == 1) ? best : sec_best;

    if (decider == 2)
        cout << "2nd best ";

    cout << "Shortest distance from " << source << " to every other node: " << endl;
    for (ll i = 1; i <= v; i++)
    {
        cout << i << " : ";
        if (container[i] == INF)
            cout << " unreachable " << endl;
        else
            cout << container[i] << endl;
    }
}

int main()
{
    ll v, e;
    cin >> v >> e;

    initialize(v);

    for (ll i = 1; i <= e; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    cout << "Enter Source: ";
    ll source;
    cin >> source;

    dijkstra_sparse(source);

    ll dest;
    cout << "Enter Destination: ";
    cin >> dest;

    cout << "Enter 1 to explore shortest path and 2 for second best shortest path: ";
    ll pathType;
    cin >> pathType;

    if (pathType == 1)
    {
        cout << "Shortest Path: \n";
        }
    else if (pathType == 2)
        cout << "2nd best Shortest Path: \n";
    else
    {
        cout << "Not available ! Try Yen's algorithm to find Kth shortest path." << endl;
        return 0;
    }

    // dealing with shortest path
    vector<ll> path = getPath(source, dest, pathType);

    if (path.empty())
    {
        cout << "Unreachable\n";
    }
    else
    {
        for (auto x : path)
            cout << x << " ";
        cout << '\n';
    }
}