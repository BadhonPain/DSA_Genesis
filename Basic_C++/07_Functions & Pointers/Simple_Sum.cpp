#include <iostream>
using namespace std;
int Summation(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = sum + i;
    }
    return sum;
}

int main()
{
    int num;
    cin >> num;
    int sum = Summation(num);
    cout << sum;
    return 0;
}