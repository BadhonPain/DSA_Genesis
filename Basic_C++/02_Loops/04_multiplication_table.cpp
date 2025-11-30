#include <iostream>
using namespace std;

int main()
{
    int n, fact = 1;
    cout << "Kotor Ghorer Namta?" << endl;
    cin >> n;
    for (int i = 1; i <= 10; i++)
    {
        cout << n << "x" << i << " " << "=" << " " << i * n << endl;
    }

    return 0;
}