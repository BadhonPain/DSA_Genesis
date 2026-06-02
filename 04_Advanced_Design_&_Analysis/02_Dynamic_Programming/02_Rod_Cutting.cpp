#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rodCutting(const vector<int> &price, int n)
{
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int maxVal = -1;
        for (int j = 0; j < i; j++)
        {
            maxVal = max(maxVal, price[j] + dp[i - j - 1]);
        }
        dp[i] = maxVal;
    }
    return dp[n];
}

int main()
{
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20}; // price for length 1..8
    int n = price.size();
    cout << "Max Profit: " << rodCutting(price, n) << "\n";
    return 0;
}
