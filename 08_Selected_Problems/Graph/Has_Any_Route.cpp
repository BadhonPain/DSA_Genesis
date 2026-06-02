#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "Enter Vertex count: ";
    int V,E;
    cin >> V;
    cout << "Enter Edge count: ";
    cin>>E;
    vector<vector<int>> adjMatrix(V, vector<int>(V, 0));
    cout << "Enter edges: " << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
    }

    cout << "Enter target nodes: ";
    int t1, t2;
    cin >> t1 >> t2;
    if (adjMatrix[t1][t2])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}