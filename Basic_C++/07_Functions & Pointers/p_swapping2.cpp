#include <iostream>
using namespace std;
int main()
{
    int x = 3;
    int *p = &x;
    int y = 5;
    int *q = &y;
    cout << "x= " << x << endl
         << "y= " << y << endl;
    *p = 5;
    *q = 3;
    cout << "x= " << x << endl
         << "y= " << y << endl;
}