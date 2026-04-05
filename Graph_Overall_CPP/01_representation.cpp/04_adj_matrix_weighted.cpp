#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> vc(v + 1, vector<int>(v + 1, -1));

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c; // weight should be positive or 0
        vc[a][b] = c;
        vc[b][a] = c;      // remove this if directed
    }

    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            cout << vc[i][j] << " ";
        }

        cout << endl;
    }
}