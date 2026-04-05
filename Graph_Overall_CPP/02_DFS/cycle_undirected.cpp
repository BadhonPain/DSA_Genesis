#include <bits/stdc++.h>
using namespace std;

bool hasCycleDfs(int source, int parent, vector<bool> &visited, const vector<vector<int>> &vc)
{
    visited[source] = true;

    for (auto x : vc[source])
    {
        if (!visited[x])
        {
            if (hasCycleDfs(x, source, visited, vc))
                return true;
        }
        else if (x != parent)
            return true;
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
    /* if connected graph guranteed
      int source;
      cout << "Enter Starting Node(1-" << v << "): ";
      cin >> source;
    if (hasCycleDfs(source, -1, visited, vc))
      cout << "Cycle Found !" << endl;
    else
    cout << "Cycle Not Found !" << endl;
    */

    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            if (hasCycleDfs(i, -1, visited, vc))
            {
                cout << "Cycle Found !" << endl;
                return 0;
            }
        }
    }
    cout << "Cycle Not Found !" << endl;
}