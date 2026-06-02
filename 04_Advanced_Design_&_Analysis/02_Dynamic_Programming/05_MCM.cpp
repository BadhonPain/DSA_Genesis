#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int matrixChainMultiplication(const vector<int> &p)
{
    int n = p.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[1][n];
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 30}; // Dimensions of matrices A1(10x20), A2(20x30), A3(30x40), A4(40x30)
    cout << "Minimum Multiplications: " << matrixChainMultiplication(arr) << "\n";
    return 0;
}
