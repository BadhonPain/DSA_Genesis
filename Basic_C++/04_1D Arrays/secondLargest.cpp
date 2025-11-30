#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n;

    cout << "Enter array size: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // int max = arr[0];
    int MAX = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        // max = (arr[i] > max) ? arr[i] : max;
        MAX = max(MAX, arr[i]);
    }
    // int smax = arr[0];
    int smax = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        // if (max != arr[i])
        // smax = (arr[i] > smax) ? arr[i] : smax;
        if (MAX != arr[i])
            smax = max(smax, arr[i]);
    }
    cout << smax;
}