#include <iostream>
#include <list>
#include <queue>
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

    void bfs()
    {
        queue<int> q;
        q.push(0);
        vector<bool> v(Vertex, false);
        v[0] = true;

        while (!q.empty())
        {
            int src = q.front();
            q.pop();

            cout << src << " ";

            for (auto dst : l[src])
            {
                if (!v[dst])
                {
                    v[dst] = true;
                    q.push(dst);
                }
            }
        }
    }
};
int main()
{
    Graph gr(5);

   gr.addEdge(0,1);
   gr.addEdge(0,2);
   gr.addEdge(0,3);
   gr.addEdge(2,1);
   gr.addEdge(2,3);
   gr.addEdge(3,4);
   gr.addEdge(1,4);

    gr.bfs();
}