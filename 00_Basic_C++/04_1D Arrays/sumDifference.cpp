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
    int Oddsum = 0, Evensum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            Evensum += arr[i];
        else
            Oddsum += arr[i];
    }
    cout << Evensum - Oddsum;
}