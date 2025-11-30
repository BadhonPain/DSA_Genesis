#include <iostream>
using namespace std;
int main()
{
    int x = 3;
    int *p;
    p = &x;
    cout << &x << endl; // 0x61ff08 -> address of 'x'
    cout << p << endl;  // 0x61ff08 -> address of 'x' using pointer

    cout << x << endl; // value of 'x'
    cout << *p << endl; // value of 'x'-> de-reference operator
    cout << &p << endl; // 0x61ff08
}