#include <iostream>
using namespace std;
int main()
{
    string s = "12345";
    int a = stoi(s);
    cout << a << endl; // here a is become a number form of that string
    cout << a + 1 << endl;
}