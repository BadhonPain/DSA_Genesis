#include <iostream>
using namespace std;
void usa()
{
    cout << "You are in USA\n";
    return;
}
void india()
{
    cout << "You are in India\n";
    usa();
}
int main()
{

    cout << "You are in main\n";
    india();

    return 0;
}