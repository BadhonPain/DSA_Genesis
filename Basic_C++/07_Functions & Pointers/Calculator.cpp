#include <iostream>
using namespace std;
// Basic Calculator

int factorial(int x)
{
    int fact = 1;
    for (int i = 1; i <= x; i++)
    {

        fact *= i;
    }
    return fact;
}

int Summation(int m, int n)
{
    return m + n;
}
int Multiplication(int m, int n)
{
    return m * n;
}
int Subtraction(int m, int n)
{
    return m - n;
}
float Division(int m, int n)
{
    return (float)m / n;
}

int main()
{
    int a, b;
    cout << "You are enjoying a simple & basic calculator.\n"
         << "Press 'p' to calculate permutation and Press 'c' for combination." << "\nPress 'x' to discontinue.\n"
         << "\t\t\t   By Badhon Pain" << endl;

    while (1)
    {
        cout << "Choose an operation: (+,-,x,/)" << endl;
        char x;
        cin >> x;
        if (x == 'x')
            break;
        else if (x == '+')
        {
            cout << "Enter two numbers: ";
            cin >> a >> b;
            int sum = Summation(a, b);
            cout << "Answer is: " << sum << endl;
        }
        else if (x == '-')
        {
            cout << "Enter two numbers: ";
            cin >> a >> b;
            int sub = Subtraction(a, b);
            cout << "Answer is: " << sub << endl;
        }
        else if (x == '*')
        {
            cout << "Enter two numbers: ";
            cin >> a >> b;
            int mult = Multiplication(a, b);
            cout << "Answer is: " << mult << endl;
        }
        else if (x == '/')
        {
            cout << "Enter two numbers: ";
            cin >> a >> b;
            if (b == 0)
            {
                cout << "Math Error!" << endl;
            }
            else
            {
                float div = Division(a, b);
                cout << "Answer is: " << div << endl;
            }
        }
        else if (x == 'c')
        {
            // nCr= n!/(r!*(n-r)!)
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
        else if (x == 'p')
        {
            // npr= n!/(n-r)!
            int n, r;
            cout << "Enter n: ";
            cin >> n;
            int nfact = factorial(n);
            cout << "Enter r: ";
            cin >> r;

            int nrfact = factorial(n - r);

            int nPr = nfact / nrfact;
            cout << nPr << endl;
        }

        else
        {
            cout << "Invalid Operation! Try Again. " << endl;
        }
    }
    return 0;
}