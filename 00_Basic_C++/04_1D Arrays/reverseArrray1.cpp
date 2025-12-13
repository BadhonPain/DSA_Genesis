#include <iostream>
using namespace std;
// using extra array
int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int arr[n];
    int brr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        brr[i] = arr[n - 1 - i];
        cout << brr[i] << " ";
    }
}
