#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &v, int low, int high)
{
    if (low == high)
        return v[low];

    int mid = low + (high - low) / 2;
    int maxLeft = findMax(v, low, mid);
    int maxRight = findMax(v, mid + 1, high);

    return max(maxLeft, maxRight);
}

int main()
{
    vector<int> v = {1, 4, 7, 2, 3, 9, 5, 3, 7};
    cout << findMax(v, 0, v.size() - 1) << endl;

    return 0;
}