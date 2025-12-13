#include <iostream>
// printing Reverse tringale

using namespace std;
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <=n; i++) // or, for( int i=n; i>=1; i--)
    {
        for (int j = 1; j <= n-i+1; j++) // or, for( int j=1; j=i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}