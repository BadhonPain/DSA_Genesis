#include <iostream>
using namespace std;

int main()
{
    int arr[] = {5, 1, 4, 50, 60, 27, 0, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Bubble Sort -> Ascending order
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++) // ekkhane n-1 rakhleo hbe kanona T.C same thakbe but n-1-i rakhle no. of operations kome 
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}