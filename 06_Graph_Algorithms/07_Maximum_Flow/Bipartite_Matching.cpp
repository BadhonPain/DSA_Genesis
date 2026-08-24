#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int BFS(int source, int sink, vector<vector<int>> &adj_list, vector<vector<int>> &residual_capacity, vector<int> &parent)
{
    parent.assign(adj_list.size(), -1);
    parent[source] = -2;

    queue<pair<int, int>> q;
    q.push({source, INF});

    while (!q.empty())
    {
        auto neighbour = q.front();
        int u = neighbour.first;
        int flow = neighbour.second;
        q.pop();

        for (auto x : adj_list[u])
        {
            if (parent[x] == -1 && residual_capacity[u][x])
            {
                int bottle_neck = min(flow, residual_capacity[u][x]);
                parent[x] = u;
                if (x == sink)
                    return bottle_neck;
                q.push({x, bottle_neck});
            }
        }
    }
    return 0;
}

int Edmonds_Karp(int source, int sink, vector<vector<int>> &adj_list, vector<vector<int>> &residual_capacity)
{
    int max_flow = 0;
    while (true)
    {
        vector<int> parent;
        int network_flow = BFS(source, sink, adj_list, residual_capacity, parent);
        if (network_flow == 0)
            break;
        max_flow += network_flow;

        int current = sink;
        while (current != source)
        {
            int par_current = parent[current];
            residual_capacity[par_current][current] -= network_flow;
            residual_capacity[current][par_current] += network_flow;
            current = par_current;
        }
    }

    return max_flow;
}

int main()
{
    int L, R, E;
    cin >> L >> R >> E; // L = left set size, R = right set size, E = number of edges

    vector<vector<bool>> connections(L + 1, vector<bool>(R + 1, false));

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v; 
        connections[u][v] = true;
    }

    // Building Bipartite & Flow Network
    int total_vertices = L + R + 2;
    vector<vector<int>> adj_list(total_vertices);
    vector<vector<int>> residual_capacity(total_vertices, vector<int>(total_vertices, 0));

    int source = 0;
    int sink = L + R + 1;

    for (int i = 1; i <= L; i++)
    {
        adj_list[source].push_back(i);
        adj_list[i].push_back(source);
        residual_capacity[source][i] = 1;
    }

    for (int j = 1; j <= R; j++)
    {
        adj_list[j + L].push_back(sink);
        adj_list[sink].push_back(j + L);
        residual_capacity[j + L][sink] = 1;
    }

    for (int i = 1; i <= L; i++)
    {
        for (int j = 1; j <= R; j++)
        {
            if (connections[i][j])
            {
                adj_list[i].push_back(j + L);
                adj_list[j + L].push_back(i);
                residual_capacity[i][j + L] = 1;
            }
        }
    }

    int max_matching = Edmonds_Karp(source, sink, adj_list, residual_capacity);
    cout << "Maximum Bipartite Matching: " << max_matching << endl
         << endl;

    // Reconstructing Matched Pairs
    for (int i = 1; i <= L; i++)
    {
        for (int j = 1; j <= R; j++)
        {
            if (connections[i][j] && residual_capacity[i][j + L] == 0)
            {
                cout << "Left " << i << " -> Right " << j << endl;
            }
        }
    }
}