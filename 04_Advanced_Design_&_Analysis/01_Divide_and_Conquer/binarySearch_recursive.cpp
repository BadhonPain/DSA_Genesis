#include<bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int>&v, int low, int high, int target) // O(logn)
{
    if(low>high) return false;
    int mid = low + (high-low)/2;

    if(v[mid]==target) return true;
    else if(v[mid]<target) return binarySearch(v,mid+1,high,target);
    else return binarySearch(v,low,mid-1,target);

    return false;
}

int main()
{
    vector<int> v = {1, 2, 7, 12, 33, 49, 51, 55, 83, 87};
    int target = 5;
    if (binarySearch(v,0,v.size()-1, target))
        cout << "Target Found !" << endl;
    else
        cout << "Target not Found !" << endl;
    return 0;
}