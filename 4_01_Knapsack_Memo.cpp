#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int static t[102][1002];
// n<=100
// W<=1000

int knapsack(int wt[], int val[], int W, int n)
{

    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (t[n][W] != -1)
    {
        return t[n][W];
    }

    if (wt[n - 1] <= W)
    {
        return t[n][W] = max(knapsack(wt, val, W - wt[n - 1], n - 1) + val[n - 1], knapsack(wt, val, W, n - 1));
    }
    else if (wt[n - 1] > W)
    {
        return t[n][W] = knapsack(wt, val, W, n - 1);
    }
}

void solve()
{
    memset(t, -1, sizeof(t));
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