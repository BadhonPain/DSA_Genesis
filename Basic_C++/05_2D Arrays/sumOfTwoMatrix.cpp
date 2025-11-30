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
    int a, b;
    cin >> a >> b;
    if (n != a && m != b)
    {
        cout << "Dimension Error!" << endl;
        return 0;
    }
    int brr[a][b];
    for (int i = 0; i < a; i++) // for rows
    {
        for (int j = 0; j < b; j++) // for columns
        {
            cin >> brr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] + brr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}