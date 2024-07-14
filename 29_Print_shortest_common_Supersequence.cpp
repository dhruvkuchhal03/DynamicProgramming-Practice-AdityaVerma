// https://leetcode.com/problems/shortest-common-supersequence/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    string shortestCommonSupersequence(string a, string b)
    {
        int n = a.length();
        int m = b.length();

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
                if (a[i - 1] == b[j - 1])
                {
                    t[i][j] = 1 + t[i - 1][j - 1];
                }
                else
                {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }

        int i = n, j = m;
        string ans = "";
        while (i > 0 && j > 0)
        {
            if (a[i - 1] == b[j - 1])
            {
                ans.push_back(a[i - 1]);
                i--;
                j--;
            }
            else if (t[i - 1][j] > t[i][j - 1])
            {
                ans.push_back(a[i - 1]);
                i--;
            }
            else
            {
                ans.push_back(b[j - 1]);
                j--;
            }
        }
        while (i > 0)
        {
            ans.push_back(a[i - 1]);
            i--;
        }
        while (j > 0)
        {
            ans.push_back(b[j - 1]);
            j--;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
        return ans;
    }
};

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