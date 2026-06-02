#include <iostream>
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> mp;

int ClimbingStairs(int n) // TC -> O(n) , SC -> O(n)
{
    if (mp.find(n) != mp.end())
        return mp[n];

    if (n <= 2)
        return n;

    mp[n] = ClimbingStairs(n - 1) + ClimbingStairs(n - 2);
    return mp[n];
}

int main()
{
    cout << ClimbingStairs(6) << endl;
}