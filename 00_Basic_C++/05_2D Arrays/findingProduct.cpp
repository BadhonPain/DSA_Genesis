#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    int product = 1;
    for (int i = 0; i < n; i++) // for rows
    {
        for (int j = 0; j < m; j++) // for columns
        {
            cin >> arr[i][j];
            product *= arr[i][j];
        }
    }
    cout << product << endl;
    return 0;
}