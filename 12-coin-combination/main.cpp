#include <bits/stdc++.h>
using namespace std;

int coin_combination(vector<int> v, int sum)
{
    int n = v.size();
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= sum; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i - v[j] >= 0)
                dp[i] += dp[i - v[j]];
        }
    }
    return dp[sum];
}

int main()
{
    vector<int> v{2, 3, 5};
    int sum = 9;
    cout << coin_combination(v, sum) << endl;
    return 0;
}