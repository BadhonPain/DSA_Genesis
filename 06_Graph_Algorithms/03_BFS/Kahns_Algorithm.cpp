#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> &indegree, vector<vector<int>> &adj_list)
{
    queue<int> q;
    int V = indegree.size();

    vector<int> result;

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (auto x : adj_list[u])
        {
            indegree[x]--;
            if (indegree[x] == 0)
                q.push(x);
        }
    }

    cout << "Topological Order: " << endl;

    for (auto x : result)
        cout << x << " ";
    cout << endl;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj_list(V); // 0 based indexing
    vector<int> in_degree(V, 0);

    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        in_degree[b]++;
    }

    bfs(in_degree, adj_list);
}