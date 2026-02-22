#include <iostream>
#include <list>
#include <vector>
#include <stack>
using namespace std;

class Graph
{
public:
    int V;
    list<int> *l;

    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int u, int v)
    {
        l[u].push_back(v);
    }

    ~Graph()
    {
        cout<<"Destructing...."<<endl;
        delete[] l;
    }
};

void topologicalSortingHelper(Graph &gr, int u, vector<bool> &visited, stack<int> &st)
{
    visited[u] = true;

    for (auto v : gr.l[u])
    {
        if (!visited[v])
            topologicalSortingHelper(gr, v, visited, st);
    }
    st.push(u);
}

void topologicalSorting(Graph &gr)
{
    vector<bool> visited(gr.V, false);
    stack<int> st;
    for (int i = 0; i < gr.V; i++)
    {
        if (!visited[i])
            topologicalSortingHelper(gr, i, visited, st);
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
}

int main()
{
    Graph gr(6);

    gr.addEdge(5, 0);
    gr.addEdge(5, 2);
    gr.addEdge(2, 3);
    gr.addEdge(1, 3);
    gr.addEdge(4, 0);
    gr.addEdge(4, 1);

    topologicalSorting(gr);
}