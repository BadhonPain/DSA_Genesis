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
    for (int i = deletingPos; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
} //TC-> O(n); SC-> O(1)