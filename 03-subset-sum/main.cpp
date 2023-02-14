#include <iostream>
#include <vector>
using namespace std;

int subsetSum(int *a, int n, int sum)
{
    vector<vector<int>> SS;
    SS.resize(n + 1, vector<int>(sum + 1));
    for (int j = 1; j <= sum; j++)
        SS[0][j] = 0;
    for (int i = 0; i <= n; i++)
        SS[i][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (SS[i - 1][j] == 1)
            {
                SS[i][j] = 1;
            }
            else
            {
                if (a[i - 1] > j)
                    SS[i][j] = 0;
                else
                    SS[i][j] = SS[i - 1][j - a[i - 1]];
            }
        }
    }
    return SS[n][sum];
}

int main()
{
    int a[] = {2, 3, 5, 7};
    int N = 4;
    int sum = 9;
    cout << subsetSum(a, N, sum) << endl;
    return 0;
}