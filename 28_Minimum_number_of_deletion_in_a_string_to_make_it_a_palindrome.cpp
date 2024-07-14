// https://www.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;
    }
    return 0;
}
// } Driver Code Ends

int helper(string a, string b, int n, int m)
{

    vector<vector<int>> t(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
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
                t[i][j] = t[i - 1][j - 1] + 1;
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
    return t[n][m];
}

int minDeletions(string str, int n)
{
    // complete the function here
    string b = str;
    reverse(str.begin(), str.end());
    int c = helper(str, b, n, n);
    return n - c;
}