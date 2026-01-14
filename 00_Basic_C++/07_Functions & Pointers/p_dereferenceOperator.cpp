#include <iostream>
using namespace std;
int main()
{
    int x = 3;
    int *p = &x;
    cout << x << endl; // x=3
    *p = 4;            // changing the value of 'x'
    cout << x << endl; // x=4
}