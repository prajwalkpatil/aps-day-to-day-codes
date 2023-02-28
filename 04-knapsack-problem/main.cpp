#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(const vector<int> &wt, const vector<int> &val, const int &max_weight)
{
    int N = wt.size();
    vector<vector<int>> K;
    K.resize(N + 1, vector<int>(max_weight + 1));
    for (int i = 0; i <= N; i++)
        K[i][0] = 0;
    for (int j = 0; j <= max_weight; j++)
        K[0][j] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= max_weight; j++)
        {
            if (j - wt[i - 1] < 0)
                K[i][j] = K[i - 1][j];
            else
            {
                K[i][j] = max(K[i - 1][j], (val[i - 1] + K[i - 1][j - wt[i - 1]]));
            }
        }
    }
    return K[N][max_weight];
}

int main()
{
    vector<int> val{10, 15, 20};
    vector<int> wt{1, 2, 3};
    cout << knapsack(wt, val, 6) << endl;

    return 0;
}