// #include <iostream>
// using namespace std;
// int main()
// {
//     string s;
//     cout << "Enter string: ";
//     getline(cin, s);
//     for (int i = 0; i < s.length(); i++)
//     {
//         if (s[i] % 2 == 0)
//         {
//             s[i] = 'a';
//         }
//     }
//     cout  <<"Modified String: " << s<<endl;
//     return 0;
// }
#include <iostream>
using namespace std;

int main()
{
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    for (int i = 0; i < s.length(); i += 2) // even indices: 0, 2, 4, ...
    {
        s[i] = 'a';
    }

    cout << "Modified string: " << s << endl;

    return 0;
}

