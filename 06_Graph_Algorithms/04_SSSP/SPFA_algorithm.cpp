#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll INF = LLONG_MAX;

// Optimized Bellman Ford

vector<vector<pll>> graph;
vector<ll> dist;
vector<bool> inqueue; // to track that a node already in the queueor not
vector<ll> cnt;       // count how many times a nodes distance value updated

bool SPFA(ll source, ll node_count)
{
    queue<ll> q;

    ll n = node_count;
    dist[source] = 0;
    q.push(source);
    inqueue[source] = true;

    while (!q.empty())
    {
        ll u = q.front();
        q.pop();

        inqueue[u] = false;

        for (auto x : graph[u])
        {
            auto to = x.first;
            auto weight = x.second;

            if (dist[to] > dist[u] + weight)
            {
                dist[to] = dist[u] + weight;
                if (!inqueue[to])
                {
                    q.push(to);
                    inqueue[to] = true;
                    cnt[to]++;

                    if (cnt[to] > n)
                        return false;
                }
            }
        }
    }

    return true;
}

int main()
{
    ll v, e;
    cin >> v >> e;

    graph.resize(v + 1);
    dist.assign(v + 1, INF);
    inqueue.assign(v + 1, false);
    cnt.assign(v + 1, 0);

    for (ll i = 0; i < e; i++)
    {
        ll from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
    }

    cout << "Enter source: ";
    ll source;
    cin >> source;

    if (SPFA(source, v))
    {
        cout << "Shortest Paths are: " << endl;
        for (ll i = 1; i <= v; i++)
        {
            cout << i << " : ";
            if (dist[i] == INF)
                cout << "unreachable" << endl;
            else
                cout << dist[i] << endl;
        }
    }

    else
        cout << "Negative Cycle Detected !!!" << endl;
}