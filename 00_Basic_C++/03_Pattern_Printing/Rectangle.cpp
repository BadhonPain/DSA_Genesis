#include <iostream>

using namespace std;
int main()
{
  int m, n;
  cout << "Enter m & n:(for m x n rectangle) ";
  cin >> m >> n;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      cout << "* ";
    }
    cout << "\n";
  }

  return 0;
}