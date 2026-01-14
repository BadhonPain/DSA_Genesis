#include <iostream>
using namespace std;
int main()
{
    int capacity = 100;
    int size;
    cin >> size;
    int arr[capacity];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int insertPosition;
    cin >> insertPosition;
    int insertElement;
    cin >> insertElement;
    size++;
    for (int i = size - 1; i > insertPosition; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[insertPosition] = insertElement;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
//TC -> O(n); SC-> O(1)