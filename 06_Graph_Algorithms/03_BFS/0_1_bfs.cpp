#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;

int v, e;
vector<int> dist;

void bfs(int s, vector<vector<pair<int, int>>> &graph)
{
    deque<int> dq;
    dist[s] = 0;
    dq.push_back(s);
    while (!dq.empty())
    {
        int u = dq.front();
        dq.pop_front();

        for (auto &v : graph[u])
        {
            int node = v.first;
            int wt = v.second;
            if (dist[u] + wt < dist[node])
            {
                dist[node] = dist[u] + wt;

                if (wt == 0)
                    dq.push_front(node);
                else
                    dq.push_back(node);
            }
        }
    }
}

int main()
{
    cin >> v >> e;
    dist.assign(v + 1, INF);

    vector<vector<pair<int, int>>> graph(v + 1);
    for (int i = 1; i <= e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
    }
    cout << "Enter source Node: ";
    int source;
    cin >> source;
    bfs(source, graph);

    for (int i = 1; i <= v; i++)
    {
        cout << dist[i] << " ";
    }
}