#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const ll INF = LLONG_MAX;

ll V;
vector<tll> edge_list;     // from, to, weight (original graph, 1..V)
vector<vector<pll>> graph; // original adjacency list, 1..V
vector<vector<pll>> reweighted_graph;
vector<ll> h;               // Bellman-Ford potentials from virtual source 0
vector<vector<ll>> allDist; // allDist[u][v] = shortest distance u -> v

bool Bellman_Ford() // Bellman-Ford from virtual source 0, also detects negative cycle
{
    h.assign(V + 1, INF);
    h[0] = 0;

    vector<tll> augmented_edges = edge_list;
    for (ll i = 1; i <= V; i++)
        augmented_edges.push_back({0, i, 0}); // virtual edges, weight 0

    for (ll i = 0; i < V; i++) // V+1 vertices (0..V), so V relaxations suffice
    {
        bool isChanged = false;
        for (auto edge : augmented_edges)
        {
            ll from = get<0>(edge);
            ll to = get<1>(edge);
            ll cost = get<2>(edge);

            if (h[from] < INF)
            {
                if (h[to] > h[from] + cost)
                {
                    h[to] = h[from] + cost;
                    isChanged = true;
                }
            }
        }
        if (!isChanged)
            break;
    }

    for (auto edge : augmented_edges) // Extra pass to detect negative cycle
    {
        ll from = get<0>(edge);
        ll to = get<1>(edge);
        ll cost = get<2>(edge);

        if (h[from] < INF && h[to] > h[from] + cost)
            return false;
    }

    return true;
}

void reweightGraph() // new_weight(u,v) = weight(u,v) + h[u] - h[v]  (always >= 0 if no negative cycle)
{
    reweighted_graph.assign(V + 1, {});
    for (ll from = 1; from <= V; from++)
    {
        for (auto x : graph[from])
        {
            ll to = x.first;
            ll cost = x.second;
            ll newCost = cost + h[from] - h[to];
            reweighted_graph[from].push_back({to, newCost});
        }
    }
}

vector<ll> Dijkstra(ll source)
{
    vector<ll> dist(V + 1, INF);
    dist[source] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    pq.push({0, source});
    while (!pq.empty())
    {
        auto pr = pq.top();

        ll weight = pr.first;
        ll node = pr.second;

        pq.pop();

        if (weight > dist[node]) // we don't wanna process the same nodes for multiple times for those nodes who already got best values
            continue;

        for (auto x : reweighted_graph[node])
        {
            ll neigh = x.first;
            ll wt = x.second;

            ll newDist = wt + weight;
            if (newDist < dist[neigh]) // Relaxation step
            {
                dist[neigh] = newDist;
                pq.push({newDist, neigh});
            }
        }
    }

    return dist;
}

bool Johnsons_Algorithm()
{
    if (!Bellman_Ford())
        return false; // negative cycle, all-pairs distances undefined

    reweightGraph();

    allDist.assign(V + 1, vector<ll>(V + 1, INF));

    for (ll u = 1; u <= V; u++)
    {
        vector<ll> dist = Dijkstra(u);

        for (ll v = 1; v <= V; v++)
            if (dist[v] < INF)
                allDist[u][v] = dist[v] + h[v] - h[u]; // undo the reweighting

        allDist[u][u] = 0;
    }

    return true;
}

int main()
{
    ll e;
    cin >> V >> e;

    graph.assign(V + 1, {});

    for (ll i = 0; i < e; i++)
    {
        ll from, to, cost;
        cin >> from >> to >> cost;
        edge_list.push_back({from, to, cost});
        graph[from].push_back({to, cost});
    }

    bool noNegativeCycle = Johnsons_Algorithm();

    if (!noNegativeCycle)
    {
        cout << "Negative cycle detected! Shortest paths are undefined." << endl;
        return 0;
    }

    cout << "\nAll-Pairs Shortest Distances:\n";
    for (ll i = 1; i <= V; i++)
    {
        for (ll j = 1; j <= V; j++)
        {
            cout << i << " -> " << j << " : ";
            if (allDist[i][j] == INF)
                cout << "unreachable";
            else
                cout << allDist[i][j];
            cout << endl;
        }
    }

    cout << "\nEnter source and destination to explore shortest distance : " << endl;
    ll source, dest;
    cin >> source >> dest;

    if (allDist[source][dest] == INF)
        cout << "No Path from " << source << " to " << dest << endl;
    else
        cout << "Shortest Distance: " << allDist[source][dest] << endl;

    return 0;
}