#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int helper(int e, int f, vector<vector<int>> &t)
{
    if (e == 1)
        return f;
    if (f == 0 || f == 1)
        return f;

    if (t[e][f] != -1)
        return t[e][f];

    int mn = INT_MAX;

    for (int k = 1; k <= f; k++)
    {
        int low, high;

        if (t[e - 1][k - 1] != -1)
            low = t[e - 1][k - 1];
        else
            low = helper(e - 1, k - 1, t);

        if (t[e][f - k] != -1)
            high = t[e][f - k];
        else
            high = helper(e, f - k, t);

        int temp = 1 + max(low, high);
        mn = min(mn, temp);
    }
    return t[e][f] = mn;
}

int superEggDrop(int e, int f)
{
    vector<vector<int>> t(e + 1, vector<int>(f + 1, -1));
    return helper(e, f, t);
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