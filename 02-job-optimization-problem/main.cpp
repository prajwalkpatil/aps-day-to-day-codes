#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

int countBitsSet(int n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int optimizeJob(vector<vector<int>> jobs, int N)
{
    vector<int> dp(pow(2, N), INT_MAX);
    dp[0] = 0;
    int x = 0;
    int y = 0;
    for (int i = 0; i < pow(2, N); i++)
    {
        x = countBitsSet(i);
        for (int j = 0; j < N; j++)
        {
            if (!(i & 1 << j)) // If nth bit is not set
            {
                dp[i | 1 << j] = min(dp[i | 1 << j], jobs[x][j] + dp[i]);
            }
        }
    }
    return dp[pow(2, N) - 1];
}

int main()
{
    vector<vector<int>> dp{{3, 2, 7}, {5, 1, 3}, {2, 7, 2}};
    cout << optimizeJob(dp, 3) << endl;
    return 0;
}