#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int editDistance(const string &s1, const string &s2)
{
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int j = 0; j <= n; j++)
        dp[0][j] = j;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min({dp[i - 1][j],       // Remove
                                    dp[i][j - 1],       // Insert
                                    dp[i - 1][j - 1]}); // Replace
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string s1 = "sunday";
    string s2 = "saturday";
    cout << "Edit Distance: " << editDistance(s1, s2) << "\n";
    return 0;
}
