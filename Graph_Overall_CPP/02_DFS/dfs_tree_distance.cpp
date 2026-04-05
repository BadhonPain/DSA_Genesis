#include <bits/stdc++.h>
using namespace std;

void dfsTreeDist(int source, int parent, int distance, vector<bool> &visited, const vector<vector<int>> &vc)
{ // only works for Tree, if a Graph then we need BFS (see bfs_distance.cpp)
    visited[source] = true;
    if (parent == -1)
        distance = 0;
    else
        distance++;
    cout << source << ":" << distance << endl;
    for (auto x : vc[source])
    {
        if (!visited[x])
            dfsTreeDist(x, source, distance, visited, vc);
        ;
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
    int distance;
    int source;
    cout << "Enter Starting Node(1-" << v << "): ";
    cin >> source;
    dfsTreeDist(source, -1, distance, visited, vc);
}