#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    int sum = 0;
    for (int i = 0; i < n; i++) // for rows
    {
        for (int j = 0; j < m; j++) // for columns
        {
            cin >> arr[i][j];
            sum += arr[i][j];
        }
    }
    cout << sum << endl;
    return 0;
}