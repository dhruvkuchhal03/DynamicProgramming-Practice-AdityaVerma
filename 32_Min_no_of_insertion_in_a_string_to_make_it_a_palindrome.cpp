// https://www.geeksforgeeks.org/problems/form-a-palindrome2544/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int lcs(string a, string b, int n, int m)
    {
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
                    t[i][j] = t[i - 1][j - 1] + 1;
                }
                else
                {
                    t[i][j] = max(t[i][j - 1], t[i - 1][j]);
                }
            }
        }
        return t[n][m];
    }

    int findMinInsertions(string S)
    {
        // code here
        int n = S.length();
        string a = S;
        reverse(S.begin(), S.end());
        int chk = lcs(S, a, n, n);

        return n - chk;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.findMinInsertions(S) << endl;
    }
    return 0;
}

// } Driver Code Ends