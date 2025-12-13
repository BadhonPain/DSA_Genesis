#include <iostream>
using namespace std;

int main()
{
    int arr[] = {5, 1, 4, 50, 60, 27, 0, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Bubble Sort -> Ascending order (Optimize)
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = true;
        for (int j = 0; j < n - 1 - i; j++) // ekkhane n-1 rakhleo hbe kanona T.C same thakbe but n-1-i rakhle no. of operations kome
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = false; // as the flage is false, that means swapping is happening
            }
        }
        if (flag == true)
            break;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    // for worst case, no. of ops -> n*(n-1)/2 & T.C -> O(n^2)
    // for avg. case, T.C -> O(n^2) 
    // for best case, no. of ops -> n & T.C -> O(n)
}