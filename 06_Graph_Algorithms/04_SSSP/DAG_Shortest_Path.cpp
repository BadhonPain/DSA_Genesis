#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int INF = 1e9;

int n, m;
vector<vector<pii>> adj;
vector<bool> vis;
stack<int> st;

void dfs(int u)
{
    vis[u] = true;

    for (auto [v, w] : adj[u])
    {
        if (!vis[v])
            dfs(v);
    }

    st.push(u);
}

int main()
{
    cin >> n >> m;

    adj.resize(n);
    vis.assign(n, false);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
    }

    int source;
    cin >> source;

    // Topological Sort
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i);
    }

    // Shortest Path
    vector<int> dist(n, INF);
    dist[source] = 0;

    while (!st.empty())
    {
        int u = st.top();
        st.pop();

        if (dist[u] == INF)
            continue;

        for (auto [v, w] : adj[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    cout << "Shortest distances from source " << source << ":\n";

    for (int i = 0; i < n; i++)
    {
        cout << i << " : ";

        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }

    return 0;
}