#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string s = "badhon";
    cout << s << endl;
    reverse(s.begin(), s.end()); //effective way & the reverse fn doesn't return a value
    // As, we can't write string rev= reverse(s.begin(), s.end()); (it just modifies the string s)


    
    //ANARI METHOD
    // char n = s.length();
    // int i = 0;
    // int j = n - 1;
    // while (i < j)
    // {
    //     int temp = s[i];
    //     s[i] = s[j];
    //     s[j] = temp;
    //     i++;
    //     j--;
    // }
    
    cout << s << endl;
}