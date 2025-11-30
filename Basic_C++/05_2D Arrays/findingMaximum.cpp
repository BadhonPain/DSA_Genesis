#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    int MAX = INT_MIN;
    for (int i = 0; i < n; i++) // for rows
    {
        for (int j = 0; j < m; j++) // for columns
        {
            cin >> arr[i][j];
            MAX = max(MAX, arr[i][j]);
        }
    }
    cout << MAX << endl;
    return 0;
}