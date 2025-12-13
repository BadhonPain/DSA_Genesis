#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }
    int brr[n];
    for (int i = 0; i <= n; i++)
    {
        if (brr[arr[i]] == 1)
        {
            cout << arr[i];
            break;
        }

        brr[arr[i]] = 1;
    }
    // facing space complexity due to generating extra array
}