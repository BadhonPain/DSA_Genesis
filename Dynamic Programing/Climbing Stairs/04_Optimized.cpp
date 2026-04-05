#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int ClimbingStairs(int n) // TC -> O(n) , SC -> O(1)
{
    if (n <= 2)
        return n;
    int a = 1, b = 2;

    for (int i = 3; i <= n; i++)
    {
        int c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main()
{
    cout << ClimbingStairs(6) << endl;
}