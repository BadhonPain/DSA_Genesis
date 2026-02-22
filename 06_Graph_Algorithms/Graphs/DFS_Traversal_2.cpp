#include <iostream>
#include <vector>
using namespace std;
#define N 4
// Unweighted Undirected

void dfs(vector<int> v[], int st, vector<bool> &visited)
{

    visited[st] = true;
    cout << st << " ";

    for (auto i : v[st])
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs(v, i, visited);
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
    vector<bool> visited(N, false);
    dfs(adj, starting, visited);
}