#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    string s = to_string(num);
    cout << s.length() << endl;
}