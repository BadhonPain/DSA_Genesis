#include <iostream>
using namespace std;
// nCr= n!/(r!*(n-r)!)
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
    int nfact = factorial(n);
    cout << "Enter r: ";
    cin >> r;
    int rfact = factorial(r);
    int nrfact = factorial(n - r);

    int nCr = nfact / (rfact * nrfact);
    cout << nCr << endl;
}