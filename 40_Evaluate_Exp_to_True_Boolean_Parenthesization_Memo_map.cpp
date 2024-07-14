// using map

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    unordered_map<string, int> mp;

    int solve(string s, int i, int j, bool isTrue)
    {
        if (i > j)
            return false;
        if (i == j)
        {
            if (isTrue == true)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }

        string temp = to_string(i);
        temp.push_back(' ');
        temp.append(to_string(j));
        temp.push_back(' ');
        temp.append(to_string(isTrue));

        if (mp.find(temp) != mp.end())
        {
            return mp[temp];
        }

        int ans = 0;
        for (int k = i + 1; k < j; k += 2)
        {
            int lt = solve(s, i, k - 1, true);
            int lf = solve(s, i, k - 1, false);
            int rt = solve(s, k + 1, j, true);
            int rf = solve(s, k + 1, j, false);

            if (s[k] == '&')
            {
                if (isTrue == true)
                {
                    ans = ans + lt * rt;
                }
                else
                {
                    ans = ans + lf * rt + lf * rf + lt * rf;
                }
            }
            else if (s[k] == '|')
            {
                if (isTrue == true)
                {
                    ans = ans + lf * rt + lt * rt + lt * rf;
                }
                else
                {
                    ans = ans + lf * rf;
                }
            }
            else if (s[k] == '^')
            {
                if (isTrue == true)
                {
                    ans = ans + lt * rf + lf * rt;
                }
                else
                {
                    ans = ans + lt * rt + lf * rf;
                }
            }
        }
        return mp[temp] = ans;
    }

    int countWays(int n, string s)
    {
        // code here
        mp.clear();
        return solve(s, 0, n - 1, true);
    }
};

//{ Driver Code Starts.

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

        Solution ob;
        cout << ob.countWays(n, s) << "\n";
    }
    return 0;
}
// } Driver Code Ends



