// https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int LongestRepeatingSubsequence(string str)
    {
        // Code here
        string a = str;
        string b = str;
        int n = str.size();
        int m = n;

        vector<vector<int>> t(n + 1, vector<int>(m + 1, -1));

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                    t[i][j] = 0;
            }
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if ((a[i - 1] == b[j - 1]) && i != j)
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
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.LongestRepeatingSubsequence(str);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends