#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cout << "Enter string: ";
    getline(cin, s);
    cout << s << endl;
    int m, l;
    cout << "From where to where: ";
    cin >> m >> l;
    reverse(s.begin() + m - 1, s.begin() + l + 1);
    cout << s << endl;
}