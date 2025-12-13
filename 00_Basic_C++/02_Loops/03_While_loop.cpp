#include <iostream>
using namespace std;
int main()
{
    int i;
    // for (int i = 5; i <= 100; i += 5)
    // {

    //     cout << "\t" << i;
    // }
    i = 1;
    while (i <= 100)
    {
        if (i % 5 == 0)
        {
            cout << "\t" << i;
        }
        i++;
    }

    return 0;
}