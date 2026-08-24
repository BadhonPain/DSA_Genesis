#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int BFS(int source,
        int sink,
        vector<vector<int>> &adj_list,
        vector<vector<int>> &residual_capacity,
        vector<int> &parent)
{
    parent.assign(adj_list.size(), -1);

    parent[source] = -2;

    queue<pair<int, int>> q;
    q.push({source, INF});

    while (!q.empty())
    {
        auto u = q.front().first;
        auto flow = q.front().second;
        q.pop();

        for (auto v : adj_list[u])
        {
            if (parent[v] == -1 &&
                residual_capacity[u][v] > 0)
            {
                parent[v] = u;

                int bottle_neck =
                    min(flow, residual_capacity[u][v]);

                if (v == sink)
                    return bottle_neck;

                q.push({v, bottle_neck});
            }
        }
    }

    return 0;
}

void printPath(int source, int sink, vector<int> &parent)
{
    vector<int> path;

    int current = sink;

    while (current != source)
    {
        path.push_back(current);
        current = parent[current];
    }

    path.push_back(source);

    reverse(path.begin(), path.end());

    cout << "Path: ";

    for (int i = 0; i < (int)path.size(); i++)
    {
        cout << path[i];

        if (i != path.size() - 1)
            cout << " -> ";
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    int source = 0;
    int sink = N - 1;

    vector<vector<int>> adj_list(N);
    vector<vector<int>> residual_capacity(
        N, vector<int>(N, 0));

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);

        residual_capacity[u][v] += w;
    }

    int max_flow = 0;

    while (true)
    {
        vector<int> parent;

        int network_flow =
            BFS(source, sink,
                adj_list,
                residual_capacity,
                parent);

        if (network_flow == 0)
            break;

        printPath(source, sink, parent);
        cout << " | Bottleneck = "
             << network_flow << endl;

        max_flow += network_flow;

        int current = sink;

        while (current != source)
        {
            int p = parent[current];

            residual_capacity[p][current] -= network_flow;
            residual_capacity[current][p] += network_flow;

            current = p;
        }
    }

    cout << "\nMaximum Flow = "
         << max_flow << endl;
}