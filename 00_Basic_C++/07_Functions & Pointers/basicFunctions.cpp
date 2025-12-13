#include <iostream>
using namespace std;
void usa()
{
    cout << "You are in USA\n";
    return ; // the usa fn ends here that's why You are in USA printing once 
    cout << "You are in USA\n";
}
void india()
{
    cout << "You are in India\n";
}
int main()
{

    cout << "You are in main\n";
    india();
    usa();

    return 0;
}
// main fn can't be called more than once
// return -> some kind of return but not absoulately
// here, int, void, float is called return type