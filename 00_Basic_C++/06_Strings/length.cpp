#include <iostream>
using namespace std;
int main()
{
string s= "badhon"; // 7 size but accessible 6 
// bcz last one is null character(/0)
cout <<s.length() <<endl; //or
cout <<s.size() <<endl;
cout <<s[6]; //or
char x='\0';
cout <<x; // nothing will be printed
}
