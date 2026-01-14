#include <iostream>
using namespace std;
int main()
{
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int insertPosition;
    cin >> insertPosition;
    int insertElement;
    cin >> insertElement;
    size++;
    int brr[size];
    for (int i = 0; i < insertPosition; i++)
    {
        brr[i] = arr[i];
    }
    brr[insertPosition] = insertElement;
    for (int i = insertPosition + 1; i < size; i++)
    {
        brr[i] = arr[i - 1];
    }
    for (int i = 0; i < size; i++)
    {
        cout << brr[i] << " ";
    }
} // TC -> O(n); SC-> O(n)