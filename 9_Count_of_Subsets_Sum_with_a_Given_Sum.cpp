//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> t(n+1, vector<int>(sum+1,0));
        int mod = 1e9 + 7;
        
        for(int i = 0; i<=n; i++){
            t[i][0] = 1;
        }
        for(int j = 0; j<=sum; j++){
            t[0][j] = 0;
        }
        t[0][0] = 1;
        
        for(int i = 1; i<=n; i++){
            for(int j = 0; j<=sum; j++){
                if(arr[i-1]<=j){
                    t[i][j] = (t[i-1][j] + t[i-1][j-arr[i-1]])%mod;
                }else{
                    t[i][j] = (t[i-1][j])%mod;
                }
            }
        }
        return t[n][sum];
        
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends