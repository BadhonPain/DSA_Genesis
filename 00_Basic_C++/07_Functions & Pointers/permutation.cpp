#include <iostream>
using namespace std;
// nPr= n!/(n-r)!
int factorial(int x)
{
    int fact = 1;
    for (int i = 1; i <= x; i++)
    {

        fact *= i;
    }
    return fact;
}
int main()
{
    int n, r;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter r: ";
    cin >> r;
    int nfact = factorial(n);

    int nrfact = factorial(n - r);

    int nPr = nfact / nrfact;
    cout << nPr << endl;
}