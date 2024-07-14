//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int t[501][501];

    bool isPalin(string &s, int i, int j)
    {
        while (i <= j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }

    int helper(string &s, int i, int j)
    {
        if (i >= j || isPalin(s, i, j))
            return t[i][j] = 0;
        if (t[i][j] != -1)
            return t[i][j];

        int mn = INT_MAX;

        for (int k = i; k <= j - 1; k++)
        {
            int left, right;

            if (t[i][k] != -1)
                left = t[i][k];
            else
                left = helper(s, i, k);

            if (t[k + 1][j] != -1)
                right = t[k + 1][j];
            else
                right = helper(s, k + 1, j);
            int temp = 1 + left + right;
            if (temp < mn)
                mn = temp;
        }
        return t[i][j] = mn;
    }

    int palindromicPartition(string str)
    {
        // code here
        memset(t, -1, sizeof(t));
        return helper(str, 0, str.length() - 1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
}
// } Driver Code Ends