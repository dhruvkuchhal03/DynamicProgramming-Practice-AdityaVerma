#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int knapsack(int wt[], int val[], int W, int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (wt[n - 1] <= W)
    {
        return max(knapsack(wt, val, W - wt[n - 1], n - 1) + val[n - 1], knapsack(wt, val, W, n - 1));
    }
    else if (wt[n - 1] > W)
    {
        return knapsack(wt, val, W, n - 1);
    }
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