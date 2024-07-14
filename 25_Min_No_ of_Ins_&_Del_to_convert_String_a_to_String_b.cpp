// https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
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

    int minOperations(string str1, string str2)
    {
        // Your code goes here
        int n = str1.length();
        int m = str2.length();

        int lcs = helper(str1, str2, n, m);

        return (n + m - lcs - lcs);
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        Solution ob;
        cout << ob.minOperations(s1, s2) << "\n";
    }
    return 0;
}

// } Driver Code Ends