#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cout << "Enter string (length must be even): ";

    getline(cin, s);
    cout << s << endl;
    int n = s.length();
    reverse(s.begin(), s.begin() + n / 2);
    // ANARI METHOD
    //   int n = s.length();
    //     int i = 0;
    //     int j = n/2 - 1;
    //     while (i < j)
    //     {
    //         char temp = s[i];
    //         s[i] = s[j];
    //         s[j] = temp;
    //         i++;
    //         j--;
    //     }
    cout << s << endl;
}