#include <bits/stdc++.h>
using namespace std;

bool hasCycleBfs(int source, vector<bool> &visited, const vector<vector<int>> &vc)
{
    visited[source] = true;
    queue<pair<int, int>> q;
    q.push({source, -1});

    while (!q.empty())
    {
        int u = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto x : vc[u])
        {
            if (!visited[x])
            {
                visited[x] = true;
                q.push({x, u});
            }

            else if (x != parent)
                return true;
        }
    }
    return false;
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

    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {

            if (hasCycleBfs(i, visited, vc))
            {
                cout << "Cycle Found !" << endl;
                return 0;
            }
        }
    }
    cout << "Cycle Not Found !" << endl;
}