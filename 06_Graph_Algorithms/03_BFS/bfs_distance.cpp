#include <bits/stdc++.h>
using namespace std;

void bfs(int source, vector<bool> &visited, const vector<vector<int>> &vc, vector<int> &distance)
{
    visited[source] = true;
    distance[source] = 0;
    queue<int> q;
    q.push(source);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto x : vc[u])
        {
            if (!visited[x])
            {
                visited[x] = true;
                distance[x] = distance[u] + 1;
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
    vector<int> distance(v + 1, -1);

    int source;
    cout << "Enter Starting Node(1-" << v << "): ";
    cin >> source;
    bfs(source, visited, vc, distance);
    cout << "Distance List: " << endl;

    for (int i = 1; i <= v; i++)
    {
        cout << i << ": " << distance[i] << endl;
    }
}