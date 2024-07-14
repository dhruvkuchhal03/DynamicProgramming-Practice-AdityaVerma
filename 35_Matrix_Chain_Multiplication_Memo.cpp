//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int helper(int arr[], int i, int j, vector<vector<int>> &t)
    {
        if (i >= j)
            return 0;

        if (t[i][j] != -1)
            return t[i][j];

        int ans = INT_MAX;

        for (int k = i; k < j; k++)
        {
            int temp = helper(arr, i, k, t) + helper(arr, k + 1, j, t) + arr[i - 1] * arr[k] * arr[j];
            ans = min(ans, temp);
        }
        return t[i][j] = ans;
    }

    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> t(N + 1, vector<int>(N + 1, -1));
        return helper(arr, 1, N - 1, t);
        ;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends