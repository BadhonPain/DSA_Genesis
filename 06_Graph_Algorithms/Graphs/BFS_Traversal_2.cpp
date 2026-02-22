#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define N 4
// Unweighted Undirected

void bfs(int u, vector<int> adj[])
{
    queue<int> q;
    vector<bool> visited(N, false);

    visited[u] = true;
    q.push(u);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (auto i : adj[v])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    vector<int> adj[N];
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(0);
    adj[0].push_back(3);

    int starting = 0;
    bfs(starting, adj);
}