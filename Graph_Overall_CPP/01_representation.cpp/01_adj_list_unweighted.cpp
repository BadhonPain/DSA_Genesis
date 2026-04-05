#include <bits/stdc++.h>

using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> vc(v + 1);

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        vc[a].push_back(b);
        vc[b].push_back(a); // remove this if directed
    }

    for (int i = 1; i <= v; i++)
    {
        cout << i << ": ";
        for (auto x : vc[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}