// https://leetcode.com/problems/is-subsequence/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    int lcs(int n, int m, string str1, string str2)
    {
        // your code here
        vector<vector<int>> t(n + 1, vector<int>(m + 1, -1));

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                {
                    t[i][j] = 0;
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    t[i][j] = 1 + t[i - 1][j - 1];
                }
                else
                {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }
        return t[n][m];
    }

    bool isSubsequence(string s, string t)
    {
        if (lcs(s.length(), t.length(), s, t) == s.length())
            return true;
        return false;
    }
};

bool isSubsequence(string s, string t)
{
    int n = s.length();
    int m = t.length();

    if (n > m)
        return false;

    int i = 0;
    int j = 0;

    while (j <= m)
    {
        if (i == n)
            return true;

        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return false;
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