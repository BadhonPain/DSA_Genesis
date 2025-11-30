// Here, three methods of swapping is written.
//   You can just run once at a time so you have comment out two others while running one code.
#include <iostream>
using namespace std;
// using extra variable
int main()
{
    int a = 5, b = 6, temp;
    cout << a << " " << b << endl;
    temp = a;
    a = b;
    b = temp;
    cout << a << " " << b << endl;
}
// without using extra variable
int main()
{
    int a = 5, b = 6;
    cout << a << " " << b << endl;
    a = a + b;
    b = a - b;
    a = a - b;

    cout << a << " " << b << endl;
}
// using function
void swap(int &a, int &b) // pass by reference
{
    // cout<<&a<<endl;
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    int a = 5, b = 6;
    // cout<<&a<< endl; //duita 'a' er address same hbe na
    cout << a << " " << b << endl;

    swap(a, b);
    cout << a << " " << b << endl;
}
// using pointer & function
void swap(int *a, int *b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int a = 5, b = 6;

    cout << a << " " << b << endl;

    swap(&a, &b); // pass by reference
    cout << a << " " << b << endl;
}