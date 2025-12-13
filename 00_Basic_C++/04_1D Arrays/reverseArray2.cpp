#include <iostream>
using namespace std;
//  without using extra array
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
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}