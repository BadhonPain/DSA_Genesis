#include <iostream>
using namespace std;
int main()
{
    int arr[] = {42, 1, 21, 38, 30, 2, 15, 23, 0, 9};
    int size = 10;
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
