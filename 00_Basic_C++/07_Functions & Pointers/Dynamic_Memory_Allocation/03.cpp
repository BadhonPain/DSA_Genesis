// printing transpose matrix
#include <iostream>
using namespace std;
int main()
{
    int row, col;
    cin >> row >> col;
    int **matrix = new int *[row];
    for (int i = 0; i < row; i++)
    {
        matrix[i] = new int[col];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> *(*(matrix + i) + j);
        }
    }

    cout << "The Mtarix formed like this (" << row << "X" << col << ") "
         << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }

    cout << "Transpose Matrix" << " (" << col << "X" << row << ") "
         << endl;

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << *(*(matrix + j) + i) << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < row; i++)
    {
        delete[] (matrix + i);
    }
    delete[] matrix;
}