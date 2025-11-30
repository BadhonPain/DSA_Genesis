#include <iostream>
using namespace std;
int main()
{
    int n, sum = 0;
    cout << "Size of n: " << sizeof(n) << endl;
    cout << "Enter Array size: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    cout << "Size of array(bytes): " << sizeof(arr) << endl;
    cout << sum;
}