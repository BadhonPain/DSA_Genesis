#include <iostream>
using namespace std;
int sum(int a, int b) // a,b -> formal parameters
{
    return a + b;
}
int main()
{
    int a, b;
    cout << "Enter first number: " << endl;
    cin >> a;

    cout << "Enter second number: " << endl;
    cin >> b;

    cout << sum(a, b); //pass by value
}