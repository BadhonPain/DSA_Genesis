#include <iostream>
#include <cstdlib>
using namespace std;
void printHW()
{
    cout << "Hello World! " << endl;
}
int *Add(int *a, int *b)
{
    int *c = new int;
    *c = *a + *b;
    return c;
}
int main()
{
    int a, b;
    cin >> a >> b;
    int *result = Add(&a, &b);
    printHW();
    cout << *result << endl;
    delete result;
    
}
