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
    int sum = 0, s = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += arr[i];
    }
    s = (n * (n + 1)) / 2;
    int dup = sum - s;
    cout << dup;
    // most efficient way -> solving time and space complexity
}