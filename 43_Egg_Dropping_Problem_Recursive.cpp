#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int superEggDrop(int e, int f)
{
    if (e == 1)
        return f;
    if (f == 0 || f == 1)
        return f;

    int mn = INT_MAX;

    for (int k = 1; k <= f; k++)
    {
        int temp = 1 + max(superEggDrop(e - 1, k - 1), superEggDrop(e, f - k));
        mn = min(mn, temp);
    }
    return mn;
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