#include <iostream>
using namespace std;

int ClimbingStairs(int n)
{
    if (n <= 2)
        return n;
    return ClimbingStairs(n - 1) + ClimbingStairs(n - 2);
}

int main()
{
    cout << ClimbingStairs(6) << endl;
}