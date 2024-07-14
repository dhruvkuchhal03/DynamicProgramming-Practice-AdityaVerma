#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }

    if (sum % 2 != 0)
    {
        return false;
    }
    sum = sum / 2;

    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for (auto n : nums)
    {
        for (int i = sum; i >= n; i--)
        {
            dp[i] = dp[i] || dp[i - n];
        }
    }
    return dp[sum];
}

/*
class Solution {
public:

    bool helper(vector<int> nums, int sum, int n){
        vector<vector<bool>> t(n+1, vector<bool>(sum+1, false));

        for(int i = 1; i<=n; i++){
            t[i][0] = true;
        }
        for(int j = 1; j<=sum; j++){
            t[0][j] = false;
        }
        t[0][0] = true;

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=sum; j++){
                if(nums[i-1]<=j){
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum+=nums[i];
        }
        if(sum%2 != 0){
            return false;
        }
        else{
            return helper(nums, sum/2, n);
        }
    }
};
*/

void solve()
{
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll TEST_CASES = 1;
    cin >> TEST_CASES; // comment for single test case
    while (TEST_CASES--)
    {
        solve();
    }
    return 0;
}