#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<pair<int, int>>> vc(v + 1);

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vc[a].push_back({b, c});
        vc[b].push_back({a, c}); // remove this if directed
    }

    for (int i = 1; i <= v; i++)
    {
        cout << i << ": ";
        for (auto x : vc[i])
        {
            cout << x.first<<"(node)" << "," << x.second<<"(weight); " ;
        }
        cout << endl;
    }
}