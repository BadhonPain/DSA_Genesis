#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> vc(v + 1, vector<int>(v + 1, 0));

    for (int i = 0; i < e; i++)
    {
        int a,b;
        cin>>a>>b;
        vc[a][b] = 1;
        vc[a][b] = 1;     // remove this if directed
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