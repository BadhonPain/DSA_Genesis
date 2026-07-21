#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
    int N, E; // no of vertices and edges of graph
    cin >> N >> E;
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF)); // distance matrices of shortest path
    vector<int> e(N + 1);                                     // eccentricity of vertices
    set<int> center;                                          // center of graph
    int radius = INF;
    int diameter;

    for (int i = 1; i <= N; i++)
        dist[i][i] = 0;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    // Floyd-Warshall
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            if (dist[i][k] == INF)
                continue;
            for (int j = 1; j <= N; j++)
            {
                if (dist[k][j] == INF)
                    continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Eccentricity - How far is my farthest node?
    for (int i = 1; i <= N; i++)
    {
        e[i] = dist[i][1];
        for (int j = 1; j <= N; j++)
        {
            e[i] = max(e[i], dist[i][j]);
        }
    }

    // Radius - What has the smallest farthest distance?
    // Diameter - What is the largest shortest-path distance anywhere in the graph?
    diameter = e[1];
    for (int i = 1; i <= N; i++)
    {
        radius = min(radius, e[i]);
        diameter = max(diameter, e[i]);
    }

    // Center - Who achieved that smallest farthest distance?
    for (int i = 1; i <= N; i++)
    {
        if (e[i] == radius)
            center.insert(i);
    }

    cout << "Radius: " << radius << ", Diameter: " << diameter << endl;
    cout << "Center(s): ";
    for (int c : center)
        cout << c << " ";
    cout << "\n";
    cout << "Eccentricity: " << endl;

    for (int i = 1; i <= N; i++)
        cout << i << " : " << e[i] << endl;
}
