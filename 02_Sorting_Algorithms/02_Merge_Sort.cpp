#include <iostream>
using namespace std;

void merge(int *arr, int low, int mid, int high)
{
    int left = low, right = mid, k = 0;
    int *mergedArray = new int[high - low];
    while (left < mid && right < high)
    {
        if (arr[left] < arr[right])
            mergedArray[k++] = arr[left++];
        else
            mergedArray[k++] = arr[right++];
    }

    while (left < mid)
        mergedArray[k++] = arr[left++];
    while (right < high)
        mergedArray[k++] = arr[right++];

    for (int i = 0; i < high - low; i++)
    {
        arr[low + i] = mergedArray[i];
    }

    delete[] mergedArray;
}

void mergeSort(int *arr, int low, int high)
{
    if (high - low <= 1)
        return;
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid, high);
    merge(arr, low, mid, high);
}
int main()
{
    int arr[6] = {111, 26, 30, 4, 56, 76};
    mergeSort(arr, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
}