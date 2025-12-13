//Kadane's Algorithm
#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(arr) / sizeof(int);
    int maxSum = INT_MIN;
    int currentSum = 0;
    for (int i = 0; i < size; i++)
    {
        currentSum += arr[i];
        maxSum = max(maxSum, currentSum);
        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }
    cout << maxSum << endl;
}