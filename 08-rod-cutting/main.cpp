#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rod_cutting_product_dp(int n)
{
    vector<int> dp(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i / 2; j++)
        {
            dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
        }
    }
    return dp[n];
}

int rod_cutting_product_f(int n)
{
    if (n % 2 == 0)
        return (n / 2) * (n / 2);
    return (n / 2) * ((n / 2) + 1);
}

int main()
{
    cout << rod_cutting_product_dp(6) << endl;
    cout << rod_cutting_product_f(6) << endl;
    return 0;
}