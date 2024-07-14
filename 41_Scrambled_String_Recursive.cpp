#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool solve(string a, string b)
{
    if (a.compare(b) == 0)
        return true;
    if (a.length() <= 1)
        return false;

    int n = a.length();
    bool flag = false;

    for (int i = 1; i < n; i++)
    {
        if (((solve(a.substr(0, i), b.substr(n - i, i)) && solve(a.substr(i, n - i), b.substr(0, n - i))) == true) ||
            ((solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i, n - i), b.substr(i, n - i))) == true))
        {
            flag = true;
            break;
        }
    }
    return flag;
}

int isScramble(const string a, const string b)
{
    int n = a.length();
    int m = b.length();

    if (n != m)
        return 0;
    if (n == 0 && m == 0)
        return 1;
    if (a == b)
        return 1;

    return solve(a, b);
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