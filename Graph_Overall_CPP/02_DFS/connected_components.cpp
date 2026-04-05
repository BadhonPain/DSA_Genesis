#include <bits/stdc++.h>
using namespace std;

void dfs(int source, vector<int> &visited, const vector<vector<int>> &vc)
{
    visited[source] = 1;

    for (auto x : vc[source])
    {
        if (!visited[x])
            dfs(x, visited, vc);
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

    vector<int> visited(v + 1, 0);
    int countConnectedComponents = 0;
    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, vc);
            countConnectedComponents++;
        }
    }

    // cout << "Enter Starting Node(1-"<<v<<"): ";
    // int source;
    // cin>>source;
    // dfs(source,visited,vc);

    cout << "Connected Components: " << countConnectedComponents << endl;
    cout << "\nVisiting List: " << endl;
    for (int i = 1; i <= v; i++)
    {
        cout << i << " " << visited[i] << endl;
    }
}