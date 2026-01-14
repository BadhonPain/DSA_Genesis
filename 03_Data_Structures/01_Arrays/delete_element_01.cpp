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
    int deletingPos;
    cin >> deletingPos;
    int brr[size - 1];
    for (int i = 0; i < deletingPos; i++)
    {
        brr[i] = arr[i];
    }
    for (int i = deletingPos; i < size; i++)
    {
        brr[i] = arr[i + 1];
    }
    for (int i = 0; i < size - 1; i++)
    {
        cout << brr[i] << " ";
    }
}//TC-> O(n); SC-> O(n)