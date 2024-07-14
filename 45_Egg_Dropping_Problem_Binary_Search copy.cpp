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
    int l = 1;
    int h = f;
    int temp = 0;

    while (l <= h)
    {
        int mid = (l + h) / 2;
        int left = helper(e - 1, mid - 1, t);
        int right = helper(e, f - mid, t);
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