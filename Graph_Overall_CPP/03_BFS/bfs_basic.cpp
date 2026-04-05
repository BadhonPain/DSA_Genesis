#include <bits/stdc++.h>
using namespace std;

void bfs(int source, vector<bool> &visited, const vector<vector<int>> &vc)
{
    visited[source] = true;
    queue<int> q;
    q.push(source);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (auto x : vc[u])
        {
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> vc(v + 1);

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        vc[a].push_back(b);
        vc[b].push_back(a);
    }

    vector<bool> visited(v + 1, false);

    int source;
    cout << "Enter Starting Node(1-" << v << "): ";
    cin >> source;

    bfs(source, visited, vc);
}