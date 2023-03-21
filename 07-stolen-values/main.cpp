#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int stolen_values(const vector<int> &v)
{
    // v starts from index 1
    int n = v.size();
    vector<int> dp(n, 0);
    dp[0] = 0;
    dp[1] = v[1];
    for (int i = 2; i < n; i++)
        dp[i] = max(dp[i - 2] + v[i], dp[i - 1]);
    return dp[n - 1];
}

int main()
{
    vector<int> v{0, 9, 3, 5, 8, 2, 4, 7};
    cout << stolen_values(v) << endl;
    return 0;
}