#include <iostream>
#include <vector>
using namespace std;

vector<int> build_bst(const vector<int> &a)
{
    int size = a.size();
    int t = 0;
    int temp = 0;
    vector<int> bst(size, 0);
    for (int i = 0; i < size; i++)
    {
        t = i + 1;
        temp = a[i];
        while (t <= size)
        {
            bst[t - 1] += temp;
            t += (t & -t);
        }
    }
    return bst;
}

int main()
{
    vector<int> vc{3, 4, 1, 6, 7, 5, 2, 8};
    vector<int> bst;
    bst = build_bst(vc);
    for (auto i : bst)
    {
        cout << i << " ";
    }
    return 0;
}