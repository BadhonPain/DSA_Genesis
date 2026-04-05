#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int ClimbingStairs(int n) // TC -> O(n) , SC -> O(n)
{
    vector<int> v(n + 1, 0);
    v[1] = 1;
    v[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        v[i] = v[i - 1] + v[i - 2];
    }

    return v[n];
}

int main()
{
    cout << ClimbingStairs(6) << endl;
}