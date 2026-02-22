#include <iostream>
#include <vector>
using namespace std;
#define N 4
// Weighted Directed
int main()
{
    vector<pair<int, int>> adj[N];
    adj[0].push_back({1, 5});
    adj[1].push_back({2, 7});
    adj[1].push_back({3, 6});
    adj[2].push_back({3, 5});
    adj[3].push_back({0, 2});

    int u = 0;
    while (u < N)
    {
        cout << u << "->";
        for (auto v : adj[u])
        {
            cout << "{" << v.first << "," << v.second << "} ";
            // {connected node, weight of the edge}
        }
        cout << endl;
        u++;
    }
}