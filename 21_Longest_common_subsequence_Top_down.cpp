//{ Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
public:
    // Function to find the length of longest common subsequence in two strings.
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
};

//{ Driver Code Starts.
int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m; // Take size of both the strings as input
        string str1, str2;
        cin >> str1 >> str2; // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, str1, str2) << endl;
    }
    return 0;
}

// } Driver Code Ends