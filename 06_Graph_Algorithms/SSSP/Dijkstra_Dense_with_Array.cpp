#include <iostream>
#include <climits>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll INF = 1e18; 

// Initialization
ll v = 1000, e = 2000;
vector<vector<pll>> graph(v + 1);
vector<ll> dist(v + 1, INF);
vector<bool> visited(v + 1, false);
vector<ll> predecessor(v + 1, -1);
vector<vector<bool>> edgeExists(v + 1, vector<bool>(v + 1, false));   // for skipping duplicate edges

void Dijkstra(ll source)
{
    dist[source] = 0;

    for (ll i = 1; i <= v; i++)
    {
        ll u = -1;
        for (ll j = 1; j <= v; j++)
        {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }

        if (dist[u] == INF)
            break;

        visited[u] = true;

        for (auto x : graph[u])
        {
            ll to = x.first;
            ll weight = x.second;

            if (dist[to] > dist[u] + weight)    // Relaxation step
            {
                dist[to] = dist[u] + weight;
                predecessor[to] = u;
            }
        }
    }
}

vector<ll> getPath(ll source, ll destination)
{
    vector<ll> path;

    if (dist[destination] == INF)
        return path;

    for (ll cur = destination; cur != -1; cur = predecessor[cur]) // walking backward from destination to origin
    {
        path.push_back(cur);
        if (cur == source)
            break;              // stop once we reach the source
    }

    reverse(path.begin(), path.end());  // flipping it, since we built it backward
    return path;
}

void generate_graph()  // random graph generation
{
    mt19937_64 rng(random_device{}());
    uniform_int_distribution<ll> nodeDist(1, v);
    uniform_int_distribution<ll> weightDist(1, 100); // edge weights 1 -> 100

    ll edgesAdded = 0;
    while (edgesAdded < e)
    {
        ll u = nodeDist(rng);
        ll w = nodeDist(rng);

        if (u == w)
            continue; // skip self-loops
        if (edgeExists[u][w])
            continue; // skip duplicate edges

        ll weight = weightDist(rng);

        graph[u].push_back({w, weight});
        // graph[w].push_back({u, weight}); uncomment this line if you want a undirected graph

        edgeExists[u][w] = true;
        // edgeExists[w][u] = true;  mark both directions since graph is undirected

        edgesAdded++;
    }
}

int main()
{
    generate_graph();

    cout << "Enter source: ";
    ll source;
    cin >> source;

    Dijkstra(source);

    cout << "Shortest Path from " << source << " to everyone: " << endl;
    for (ll i = 1; i <= v; i++)
    {
        if (dist[i] == INF)
            cout << i << " : unreachable" << endl;
        else
            cout << i << " : " << dist[i] << endl;
    }

    ll destination;
    cout << "Enter destination: ";
    cin >> destination;

    vector<ll> path = getPath(source, destination);

    if (path.empty())
        cout << "No path exists from " << source << " to " << destination << endl;

    else
    {
        cout << "Path: ";
        for (ll node : path)
            cout << node << " ";
        cout << endl;
        cout << "Total distance: " << dist[destination] << endl;
    }
}