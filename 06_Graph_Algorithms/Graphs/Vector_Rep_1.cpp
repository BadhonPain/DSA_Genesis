#include <iostream>
#include <vector>
using namespace std;
#define N 4
// Unweighted Directed
int main()
{
    vector<int> adj[N];
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(3);
    adj[3].push_back(0);

    int u = 0;
    while (u < N)
    {
        cout << u << "->";
        for (auto v : adj[u])
        {
            cout << v << " ";
        }
        cout << endl;
        u++;
    }
}