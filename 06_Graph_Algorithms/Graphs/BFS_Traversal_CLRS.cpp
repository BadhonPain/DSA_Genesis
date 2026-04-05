#include <iostream>
#include <vector>
#include <queue>
using namespace std;

enum Color { WHITE, GRAY, BLACK };
const int NIL = -1;
const int infinity = INT_MAX;

void BFS(int source, vector<vector<int>> &adj, int n)
{
    vector<Color> color(n, WHITE);
    vector<int> dist(n, infinity);
    vector<int> parent(n, NIL);

    queue<int> q;

    color[source] = GRAY;
    dist[source] = 0;
    parent[source] = NIL;

    q.push(source);

    while (!q.empty())
    {
        int u = q.front();
        // print 
        q.pop();

        for (int v : adj[u])
        {
            if (color[v] == WHITE)
            {
                color[v] = GRAY;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }

        color[u] = BLACK;
    }

    cout << "Vertex  Dist  Parent\n";
    for (int i = 0; i < n; i++)
    {
        cout << i << "       " << dist[i] << "      " << parent[i] << endl;
    }
}