#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph
{
    int Vertex;
    list<int> *l;

public:
    Graph(int v)
    {
        Vertex = v;
        l = new list<int>[v];
    }

    void addEdge(int i, int j)
    {
        l[i].push_back(j);
        l[j].push_back(i);
    }

    void DFS_helper(int src, vector<bool> &visited)
    {
        cout << src<<" ";
        visited[src] = true;

        for (auto dst : l[src])
        {
            if (!visited[dst])
                DFS_helper(dst, visited);
        }
    }

    void DFS()
    {
        int src = 0;
        vector<bool> visited(Vertex, false);
        DFS_helper(src, visited);
    }
};
int main()
{

    Graph gr(5);

    gr.addEdge(0, 1);
    gr.addEdge(0, 2);
    gr.addEdge(0, 3);
    gr.addEdge(2, 1);
    gr.addEdge(2, 3);
    gr.addEdge(3, 4);
    gr.addEdge(1, 4); 

    gr.DFS();
}