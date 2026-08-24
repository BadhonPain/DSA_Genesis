#include <bits/stdc++.h>
using namespace std;

void dfs1(int source,
          vector<vector<int>> &adj_list,
          vector<int> &order,
          vector<bool> &visited)
{
    visited[source] = true;

    for (auto x : adj_list[source])
    {
        if (!visited[x])
        {
            dfs1(x, adj_list, order, visited);
        }
    }

    order.push_back(source);
}

void dfs2(int source,
          vector<vector<int>> &adj_list,
          vector<bool> &visited,
          vector<int> &component)
{
    visited[source] = true;
    component.push_back(source);

    for (auto x : adj_list[source])
    {
        if (!visited[x])
        {
            dfs2(x, adj_list, visited, component);
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj_list(V);

    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
    }

    // Find finishing order

    vector<int> t_out_order;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs1(i, adj_list, t_out_order, visited);
        }
    }

    reverse(t_out_order.begin(), t_out_order.end());

    // Transpose graph

    vector<vector<int>> transpose_list(V);

    for (int i = 0; i < V; i++)
    {
        for (auto x : adj_list[i])
        {
            transpose_list[x].push_back(i);
        }
    }

    //  Find SCCs

    visited.assign(V, false);
    vector<vector<int>> SCCs;
    int comp_size = 0;

    for (auto u : t_out_order)
    {
        if (!visited[u])
        {
            vector<int> component;

            dfs2(u, transpose_list, visited, component);

            comp_size++;

            SCCs.push_back(component);

            cout << endl;
        }
    }

    cout << "SCC count: " << comp_size << endl;
    for (int i = 0; i < SCCs.size(); i++)
    {
        cout << "SCC " << i + 1 << ": {";

        for (int j = 0; j < SCCs[i].size(); j++)
        {
            cout << SCCs[i][j];
            if (j != SCCs[i].size() - 1)
                cout << ",";
        }

        cout << "}" << endl;
    }
}