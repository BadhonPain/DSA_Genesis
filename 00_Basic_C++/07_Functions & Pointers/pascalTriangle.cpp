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
int nCr(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <=n-i-1; j++)
        {
           cout<<"  ";
        }
        
        for (int j = 0; j <= i; j++)
        {
            cout << nCr(i, j)<<"  ";
        }
        cout <<endl;
    }
}