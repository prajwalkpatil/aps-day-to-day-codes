#include <bits/stdc++.h>
using namespace std;

int edit_distance_min(const string &src, const string &dest)
{
    int m = src.size();
    int n = dest.size();
    vector<vector<int>> dp;
    dp.resize(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int j = 0; j <= n; j++)
        dp[0][j] = j;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (src[i - 1] == dest[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
        }
    }
    return dp[m][n];
}

int main()
{
    cout << edit_distance_min("apiskal", "vishal");
    return 0;
}