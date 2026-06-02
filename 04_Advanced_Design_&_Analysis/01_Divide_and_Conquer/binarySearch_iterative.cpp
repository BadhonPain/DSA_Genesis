#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> &v, int target)
{
    int low = 0;
    int high = v.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] == target)
            return true;
        else if (v[mid] < target)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return false;
}

int main()
{
    vector<int> v = {1, 2, 7, 12, 33, 49, 51, 55, 83, 87};
    int target = 51;
    if (binarySearch(v, target))
        cout << "Target Found !" << endl;
    else
        cout << "Target not Found !" << endl;
    return 0;
}