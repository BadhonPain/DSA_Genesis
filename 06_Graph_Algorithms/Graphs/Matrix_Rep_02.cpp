#include <iostream>
#include <vector>
using namespace std;

// Unweighted directed graph

int main()
{
    int node,edge;
    cin >> node>>edge;
    vector<vector<bool>> adjMat(node, vector<bool>(node,false));

    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }

    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
}