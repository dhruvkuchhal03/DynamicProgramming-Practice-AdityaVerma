//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int minCoins(vector<int> &coins, int M, int V)
    {
        // Your code goes here
        int dp[M + 1][V + 1];

        for (int j = 0; j <= V; j++)
        {
            dp[0][j] = INT_MAX - 1;
        }
        for (int i = 1; i <= M; i++)
        {
            dp[i][0] = 0;
        }

        for (int j = 1; j <= V; j++)
        {
            if (j % coins[0] == 0)
            {
                dp[1][j] = j / coins[0];
            }
            else
            {
                dp[1][j] = INT_MAX - 1;
            }
        }

        for (int i = 2; i <= M; i++)
        {
            for (int j = 1; j <= V; j++)
            {
                if (coins[i - 1] <= j)
                {
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        // if (dp[M][V] == INT_MAX - 1)
        // {
        //     return -1;
        // }
        return dp[M][V];
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for (int i = 0; i < m; i++)
            cin >> coins[i];

        Solution ob;
        cout << ob.minCoins(coins, m, v) << "\n";
    }
    return 0;
}

// } Driver Code Ends