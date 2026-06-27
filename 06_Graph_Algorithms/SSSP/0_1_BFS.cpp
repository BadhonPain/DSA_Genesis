#include <iostream>
#include <vector>
#include <climits>
#include <deque>
using namespace std;

const int INF = INT_MAX;

int v = 1000, e = 2000;
vector<vector<pair<int, int>>> graph;
vector<int> level;

void zero_one_BFS(int source)
{
    level[source] = 0;
    deque<int> dq;
    dq.push_back(source);

    while (!dq.empty())
    {
        int u = dq.front();
        dq.pop_front();

        for (auto &v : graph[u])
        {
            int node = v.first;
            int wt = v.second;

            if (level[node] > level[u] + wt)  // Relaxation
            {
                level[node] = level[u] + wt;
                if (wt == 0)
                    dq.push_front(node);
                else
                    dq.push_back(node);
            }
        }
    }
}

int main()
{
    graph.resize(v + 1);
    level.assign(v + 1, INF);

    for (int i = 1; i <= e; i++)
    {
        int a = rand() % v + 1;
        int b = rand() % v + 1;
        int w = rand() % 2;
        graph[a].push_back({b, w}); // directed graph
    }

    cout << "Enter source: ";
    int source;
    cin >> source;

    zero_one_BFS(source);

    for (int i = 1; i <= v; i++)
    {
        cout << i << " : " << level[i] << endl;
    }
}