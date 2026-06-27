#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
bool is_bipartite(int source, vector<int> &colour)
{
    queue<int> q;
    colour[source] = 0;
    q.push(source);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto x : graph[u])
        {
            if (colour[x] == -1)
            {
                colour[x] = 1 - colour[u];
                q.push(x);
            }

            else if (colour[x] == colour[u])
                return false;
        }
    }

    return true;
}
int main()
{
    int v, e;
    cin >> v >> e;
    graph.resize(v + 1);
    vector<int> colour(v + 1, -1);

    for (int i = 1; i <= e; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= v; i++)
    {
        if (colour[i] == -1)
        {
            if (!is_bipartite(i, colour))
            {
                cout << "NOT BIPARTITE" << endl;
                return 0;
            }
        }
    }
    cout << "BIPARTITE" << endl;
}