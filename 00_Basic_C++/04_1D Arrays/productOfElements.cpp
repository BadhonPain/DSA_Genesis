#include <iostream>
using namespace std;
int main()
{
    int n, fact = 1;

    cout << "Enter Array size: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        fact *= arr[i];
    }

    cout << fact;
}