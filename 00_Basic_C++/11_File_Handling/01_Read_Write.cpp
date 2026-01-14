#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    string s1,s2;
    cout <<"What youn wanna read? ";
    cin >> s1;
    ofstream out ("02_Sample.txt");
    out << s1;
    
}
