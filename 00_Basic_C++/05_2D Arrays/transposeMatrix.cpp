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
    // column wise printing
    for (int j = 0; j < m; j++) // for rows
    {
        for (int i = 0; i < n; i++) // for columns
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}