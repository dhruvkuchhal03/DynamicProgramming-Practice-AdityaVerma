//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool isPalindrome(string str, int i, int j)
    {
        while (i < j)
        {
            if (str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int helper(string s, int i, int j)
    {
        if (i >= j)
            return 0;
        if (isPalindrome(s, i, j) == true)
            return 0;

        int ans = INT_MAX;

        for (int k = i; k < j; k++)
        {
            int temp = helper(s, i, k) + helper(s, k + 1, j) + 1;
            ans = min(ans, temp);
        }
        return ans;
    }

    int palindromicPartition(string str)
    {
        // code here
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