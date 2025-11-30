#include <iostream>
using namespace std;
int main()
{
    int n;

    cout << "Enter Array size: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int MAX = arr[0];
    for (int i = 1; i < n; i++)
    {
        MAX = (arr[i] < MAX) ? MAX : arr[i];
        //    MAX= max(MAX, arr[i]);
    }
    cout << MAX;
}