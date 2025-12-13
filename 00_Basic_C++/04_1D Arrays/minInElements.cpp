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
    int MIN = arr[0];
    for (int i = 1; i < n; i++)
    {
        MIN = (arr[i] < MIN) ? arr[i] : MIN;
        // MIN = min(MIN,arr[i]);
    }
    cout << MIN;
}