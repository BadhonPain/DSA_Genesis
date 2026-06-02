#include <bits/stdc++.h>
using namespace std;
// This is not Binary Search. It's Time complexity : O(n)
bool findTarget(vector<int> &v, int low, int high, int target)
{
    if (low > high)
        return false;

    if (low == high)
        return target == v[low];

    int mid = low + (high - low) / 2;
    int inLeft = findTarget(v, low, mid, target);
    int inRight = findTarget(v, mid + 1, high, target);

    return inLeft || inRight;
}

int main()
{
    vector<int> v = {1, 4, 7, 2, 3, 9, 1, 5, 3, 7};
    int target = 20;
    if (findTarget(v, 0, v.size() - 1, target))
        cout << target << " Found !" << endl;
    else
        cout << target << " not Found !" << endl;

    return 0;
}