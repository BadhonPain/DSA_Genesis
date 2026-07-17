#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));
    vector<vector<int>> next(n + 1, vector<int>(n + 1, -1));

    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
        next[i][i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;

        // For handling multi graph
        if (w < dist[u][v])
        {
            dist[u][v] = w;
            next[u][v] = v;
        }
    }

    // Floyd-Warshall Algo
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (dist[i][k] == INF)
                continue;

            for (int j = 1; j <= n; j++)
            {
                if (dist[k][j] == INF)
                    continue;

                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];

                    // First step from i towards j
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    // Detect negative cycle
    bool negativeCycle = false;

    for (int i = 1; i <= n; i++)
    {
        if (dist[i][i] < 0)
        {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle)
    {
        cout << "Negative Cycle Exists." << endl;
        return 0;
    }

    int source, target;
    cin >> source >> target;

    if (next[source][target] == -1)
    {
        cout << "No Path !!" << endl;
        return 0;
    }

    cout << "Shortest Distance = " << dist[source][target] << endl;

    vector<int> path;

    int current = source;

    while (current != target)
    {
        path.push_back(current);
        current = next[current][target];
    }

    path.push_back(target);

    cout << "Path : ";

    for (int node : path)
        cout << node << " ";

    cout << endl;

    return 0;
}