#include <bits/stdc++.h>
using namespace std;

int computeLCS(string s1, string s2)
{
    int l1 = s1.size();
    int l2 = s2.size();
    vector<vector<int>> LCS;
    LCS.resize(l1 + 1, vector<int>(l2 + 1));

    for (int i = 0; i <= l1; i++)
    {
        LCS[i][0] = 0;
    }
    for (int j = 0; j <= l2; j++)
    {
        LCS[0][j] = 0;
    }
    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            if (s1[i] == s2[j])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }
    return LCS[l1][l2];
}

int main()
{
    string s1("abcda");
    string s2("bdabac");
    cout << computeLCS(s1, s2) << endl;
}