#include <iostream>
using namespace std;
int main()
{
    int x = 10;
    const int &ref = x; 
    x++;
    cout << ref << " " << x << " " << &ref << " " << &x << endl;
}