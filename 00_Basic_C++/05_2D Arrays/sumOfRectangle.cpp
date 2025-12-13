#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++) // for rows
    {
        for (int j = 0; j < m; j++) // for columns
        {
            cin >> arr[i][j];
        }
    }
    int c1, c2;
    cin >> c1 >> c2;
    int C1, C2;
    cin >> C1 >> C2;
    int rectSum = 0;
    for (int i = c1; i <= C1; i++) // for rows
    {
        for (int j = c2; j <= C2; j++) // for columns
        {
            rectSum += arr[i][j];
        }
    }
    cout << rectSum << endl;
    return 0;
}