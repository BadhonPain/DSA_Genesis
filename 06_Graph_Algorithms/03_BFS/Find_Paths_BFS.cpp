#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int v, e;
vector<bool> is_visited;
vector<int> parent;
vector<vector<int>> graph;

void BFS(int source)
{
    is_visited.resize(v + 1);
    parent.resize(v + 1);

    is_visited[source] = true;
    parent[source] = -1;
    queue<int> q;
    q.push(source);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto &v : graph[u])
        {
            if (!is_visited[v])
            {
                is_visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

void find_path(int start, int end)
{
    if (start == end)
    {
        cout << "Nodes are not distinct !" << endl;
        return;
    }

    int alter_end = end;

    stack<int> st;
    st.push(end);
    while (parent[end] != -1)
    {
        st.push(parent[end]);
        end = parent[end];
    }

    int len = st.size();

    cout << "Shortest Path from " << start << " to " << alter_end << " is :" << endl;
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    cin >> v >> e;
    graph.resize(v + 1);
    for (int i = 1; i <= e; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << "Enter source : ";
    int source;
    cin >> source;

    BFS(source);
    // cout << "Parent Relation: " << endl;
    // for (int i = 1; i <= v; i++)
    // {
    //     cout << i << "'s parent: " << parent[i] << endl;
    // }

    cout << "Enter start and ending node to find path between them : " ;
    int start;
    int end;
    cin >> start >> end;
    find_path(start, end);
}