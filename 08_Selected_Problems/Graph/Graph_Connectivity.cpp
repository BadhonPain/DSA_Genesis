#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph
{
    int vertex;
    list<int> *l;

public:
    Graph(int vertex)
    {
        this->vertex = vertex;
        l = new list<int>[vertex];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void dfsHelper(int source, vector<bool> &isVisited, int &vertexCount)
    {
        isVisited[source] = true;
        vertexCount++;
        for (auto dest : l[source])
        {
            if (!isVisited[dest])
                dfsHelper(dest, isVisited, vertexCount);
        }
    }

    bool isConnected(int &vertexCount)
    {
        vector<bool> isVisited(vertex, false);
        int source = 0;
        dfsHelper(source, isVisited, vertexCount);
        return vertexCount == vertex;
    }
};

int main()
{
    int V, E;
    cout << "Enter vertex count: ";
    cin >> V;
    cout << "Enter Edge count: ";
    cin >> E;

    Graph graph(V);

    int u, v;
    while (E--)
    {
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    int vertexCount = 0;

    if (graph.isConnected(vertexCount))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
