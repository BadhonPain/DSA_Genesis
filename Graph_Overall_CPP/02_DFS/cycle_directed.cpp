#include <bits/stdc++.h>
using namespace std;

bool detectCycleDfs(int source, vector<bool> &visited, vector<bool> &recStack, const vector<vector<int>> &vc)
{
    visited[source] = true;
    recStack[source] = true;

    for (auto x : vc[source])
    {
        if (!visited[x])
        {
            if (detectCycleDfs(x, visited, recStack, vc))
                return true;
        }
        else if (recStack[x])
            return true;
    }
    recStack[source] = false;
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
    }

    vector<bool> visited(v + 1, false);
    vector<bool> recStack(v + 1, false);

    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            if (detectCycleDfs(i, visited, recStack, vc))
            {
                cout << "Cycle Detected !" << endl;
                return 0;
            }
        }
    }
    cout << "Cycle Not Detected !" << endl;
}