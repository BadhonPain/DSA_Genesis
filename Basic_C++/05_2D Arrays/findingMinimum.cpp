#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    int MIN = INT_MAX;
    for (int i = 0; i < n; i++) // for rows
    {
        for (int j = 0; j < m; j++) // for columns
        {
            cin >> arr[i][j];
            MIN = min(MIN, arr[i][j]);
        }
    }
    cout << MIN << endl;
    return 0;
}