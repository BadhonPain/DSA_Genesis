#include <iostream>
using namespace std;
int main()
{
    string s = "badhon";
    cout << s << endl;
    s.push_back('i'); // push the '' character at last
    cout << s << endl;
    s.pop_back(); // remove the last character from last
    cout << s << endl;
    s.append(" pain"); // add another string after the previous one
    cout << s << endl;
    s.clear(); // clear the string & output nothing
    cout << s << endl;
    // with this STL length also varries
}