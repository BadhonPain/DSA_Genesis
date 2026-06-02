#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &v, int low, int high)
{
    if (low == high)
        return v[low];

    int mid = low + (high - low) / 2;
    int minLeft = findMin(v, low, mid);
    int minRight = findMin(v, mid + 1, high);

    return min(minLeft, minRight);
}

int main()
{
    vector<int> v = {1, 4, 7, 2, 3, 9, 1, 5, 3, 7};
    cout << findMin(v, 0, v.size() - 1) << endl;

    return 0;
}