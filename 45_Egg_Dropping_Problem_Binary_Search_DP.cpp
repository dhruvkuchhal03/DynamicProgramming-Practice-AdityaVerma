#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int superEggDrop(int e, int f)
{
    if (e == 1)
        return f;
    if (f == 0 || f == 1)
        return f;

    vector<vector<int>> t(e + 1, vector<int>(f + 1, -1));

    for (int i = 0; i <= e; i++)
    {
        t[i][0] = 0;
        t[i][1] = 1;
    }
    for (int j = 0; j <= f; j++)
    {
        t[0][j] = 0;
        t[1][j] = j;
    }

    for (int i = 2; i <= e; i++)
    {
        for (int j = 2; j <= f; j++)
        {
            int mn = INT_MAX;
            int l = 1;
            int h = j;
            int temp = 0;

            while (l <= h)
            {
                int mid = (l + h) / 2;
                int left = t[i - 1][mid - 1];
                int right = t[i][j - mid];
                temp = 1 + max(left, right);

                if (left < right)
                {
                    l = mid + 1;
                }
                else
                {
                    h = mid - 1;
                }
                mn = min(mn, temp);
            }
            t[i][j] = mn;
        }
    }

    return t[e][f];
}

void solve()
{
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll TEST_CASES = 1;
    cin >> TEST_CASES; // comment for single test case
    while (TEST_CASES--)
    {
        solve();
    }
    return 0;
}