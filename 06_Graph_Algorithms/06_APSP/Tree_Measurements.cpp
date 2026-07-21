#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<pair<int, int>>> adj;

void bfs(int src, vector<long long> &dist)
{
    dist.assign(N + 1, -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto [v, w] : adj[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + w;
                q.push(v);
            }
        }
    }
}

int main()
{
    int E;
    cin >> N >> E;
    adj.assign(N + 1, {});
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<long long> d0;
    bfs(1, d0);
    int A = max_element(d0.begin() + 1, d0.end()) - d0.begin();

    vector<long long> distA;
    bfs(A, distA);
    int B = max_element(distA.begin() + 1, distA.end()) - distA.begin();
    long long diameter = distA[B];

    vector<long long> distB;
    bfs(B, distB);

    long long radius = LLONG_MAX;
    set<int> center;
    for (int i = 1; i <= N; i++)
    {
        long long ecc = max(distA[i], distB[i]);
        if (ecc < radius)
        {
            radius = ecc;
            center = {i};
        }
        else if (ecc == radius)
            center.insert(i);
    }

    cout << radius << " " << diameter << "\n";
    for (int c : center)
        cout << c << " ";
    cout << "\n";
}