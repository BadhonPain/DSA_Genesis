#include <iostream>
using namespace std;

// Unweighted undirected graph 

int main()
{
    int node;
    cin >> node;
    int adjMat[node][node];

    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            adjMat[i][j] = 0;
        }
    }

    for (int i = 0; i < node; i++)
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