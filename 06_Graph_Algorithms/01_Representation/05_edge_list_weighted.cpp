#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;

    vector<tuple<int, int, int>> vc;

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vc.push_back({a, b, c});
    }

    for (auto [u, to, w] : vc)
    {
        cout << u << "<->" << to << " (weight:" << w << ")" << endl;
    }

    // Structured bindings that were introduced in C++17.
    // If you try to compile with older C++ standards, you get that exact error.
    // ALternate :
    /*
    for (auto t : vc)
    {
        int u = get<0>(t);
        int to = get<1>(t);
        int w = get<2>(t);
        cout << u << " <-> " << to << " (weight: " << w << ")" << endl;
    }
    */
}