#include <iostream>
#include <vector>

using namespace std;

int longest_increasing_subsequence(const vector<int> &a)
{
    int n = a.size();
    vector<int> LIS(n, 1);
    int max_length = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j] && LIS[j] + 1 > LIS[i])
            {
                LIS[i] = LIS[j] + 1;
                if (LIS[i] > max_length)
                {
                    max_length = LIS[i];
                }
            }
        }
    }
    return max_length;
}

int main()
{
    vector<int> vc{5, 11, 3, 15, 30, 25};
    cout << longest_increasing_subsequence(vc) << endl;
    return 0;
}