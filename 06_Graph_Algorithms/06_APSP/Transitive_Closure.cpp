#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> reach(n + 1, vector<bool>(n + 1, false));

    // Every vertex can reach itself
    for (int i = 1; i <= n; i++)
        reach[i][i] = true;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        reach[u][v] = true;
    }

    // Warshall Algorithm
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                reach[i][j] = reach[i][j] ||
                              (reach[i][k] && reach[k][j]);
            }
        }
    }

    // Printing transitive closure matrix
    cout << "Reachability Matrix\n";

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << reach[i][j] << " ";

        cout << endl;
    }
}