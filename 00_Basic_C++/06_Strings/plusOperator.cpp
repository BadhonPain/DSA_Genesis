#include <iostream>
using namespace std;
int main()
{
    string s = "badhon";
    cout << s << endl;
    s = s + " pain"; // substitute of append() fn, we can use it before & after both 
    cout << s << endl;
    s = " pain" + s;
    cout << s << endl;
}