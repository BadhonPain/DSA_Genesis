#include <iostream>
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
    int i;
    for (i = 0; i < n / 2; i++)
    {
        if (arr[i] != arr[n - 1 - i])

            break;
    }

    if (i == n / 2)
        cout << "PALINDROME\n";
    else
        cout << "NOT PALINDROME\n";
}