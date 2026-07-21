#include <bits/stdc++.h>
using namespace std;

void dfs(int source, vector<vector<int>> &adj_list, vector<bool> &is_visited, stack<int> &st)
{
    is_visited[source] = true;

    for (auto x : adj_list[source])
    {
        if (!is_visited[x])
            dfs(x, adj_list, is_visited, st);
    }
    st.push(source);
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

    stack<int> st;
    vector<bool> is_visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!is_visited[i])
            dfs(i, adj_list, is_visited, st);
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}