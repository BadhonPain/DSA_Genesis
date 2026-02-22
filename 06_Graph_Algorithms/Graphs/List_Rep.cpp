#include <iostream>
#include <list>
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

    void Print()
    {
        for (int i = 0; i < Vertex; i++)
        {
            cout << i << ": ";
            for (auto a : l[i])
            {
                cout << a << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    int vertex, edge;
    cin >> vertex >> edge;
    Graph gr(vertex);

    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        gr.addEdge(a, b);
    }

    gr.Print();
}