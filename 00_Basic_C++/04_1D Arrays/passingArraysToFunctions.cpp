#include <iostream>
using namespace std;
void change(int arr[]) // Array always follows pass by reference
{
    arr[2] = 4;
}
int main()
{
    int arr[3] = {1, 2, 3};
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }
    change(arr); // pass by reference
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }
}
