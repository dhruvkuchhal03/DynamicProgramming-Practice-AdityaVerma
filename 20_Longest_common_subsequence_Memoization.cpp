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
    int t[1001][1001];

    int helper(int n, int m, string str1, string str2)
    {
        if (n == 0 || m == 0)
        {
            return 0;
        }
        if (t[m][n] != -1)
            return t[m][n];

        if (str1[n - 1] == str2[m - 1])
        {
            return t[m][n] = (1 + lcs(n - 1, m - 1, str1, str2));
        }
        else
        {
            return t[m][n] = max(lcs(n - 1, m, str1, str2), lcs(n, m - 1, str1, str2));
        }
    }
    int lcs(int n, int m, string str1, string str2)
    {
        // your code here
        memset(t, -1, sizeof(t));

        return helper(n, m, str1, str2);
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