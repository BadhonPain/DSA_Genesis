#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int INF = INT_MAX;

int v, e;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> level;

void BFS(int source)
{
    visited[source] = true;
    level[source] = 0;
    queue<int> q;
    q.push(source);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto &v : graph[u])
        {
            if (!visited[v])
            {
                level[v] = level[u] + 1;
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    cin >> v >> e;
    graph.resize(v + 1);
    visited.assign(v + 1, false);
    level.assign(v + 1, INF);

    for (int i = 1; i <= e; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);   // directed graph
    }

    int source;
    cout << "Enter source: ";
    cin >> source;
    BFS(source);

    for (int i = 1; i <= v; i++)
    {
        cout << i << " : " << level[i] << endl;
    }
}