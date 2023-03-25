#include <bits/stdc++.h>
using namespace std;

int who_wins(int *a, int n)
{
    int max = INT_MIN;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            count++;
        }
    }
    if (count % 2 == 0)
        return 2;
    return 1;
}

int main()
{
    int a[] = {9, 5, 3, 6, 1, 2};
    cout << who_wins(a, 5) << endl;
    return 0;
}