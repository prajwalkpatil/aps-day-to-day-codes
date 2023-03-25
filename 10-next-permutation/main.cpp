#include <bits/stdc++.h>
using namespace std;

string get_next_permutation(string str)
{
    string s = str;
    int first = s.size() - 2;
    int second = 0;
    char temp;
    while (first > 0 && s[first] >= s[first + 1])
    {
        first--;
    }
    second = first + 1;
    int i = second;
    while (i < s.size())
    {
        if (s[i] > s[first])
        {
            if (s[i] < s[second])
            {
                second = i;
            }
        }
        i++;
    }
    temp = s[first];
    s[first] = s[second];
    s[second] = temp;
    sort(s.begin() + first + 1, s.end());
    return s;
}

int main()
{
    cout << get_next_permutation("DCFEBA") << endl;
    return 0;
}