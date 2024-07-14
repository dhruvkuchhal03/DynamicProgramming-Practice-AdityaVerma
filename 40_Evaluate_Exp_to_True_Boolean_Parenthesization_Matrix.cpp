//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int t[205][205][2];

    int solve(string s, int i, int j, bool isTrue)
    {
        if (i > j)
            return 0;
        if (i == j)
        {
            if (isTrue == true)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }

        if (t[i][j][isTrue] != -1)
            return t[i][j][isTrue];

        int ans = 0;
        for (int k = i + 1; k < j; k += 2)
        {
            // int lt = solve(s, i, k - 1, true);
            // int lf = solve(s, i, k - 1, false);
            // int rt = solve(s, k + 1, j, true);
            // int rf = solve(s, k + 1, j, false);

            int lt, lf, rt, rf;
            if (t[i][k - 1][1] != -1)
            {
                lt = t[i][k - 1][1];
            }
            else
            {
                lt = solve(s, i, k - 1, 1);
                t[i][k - 1][1] = lt;
            }
            if (t[i][k - 1][0] != -1)
            {
                lf = t[i][k - 1][0];
            }
            else
            {
                lf = solve(s, i, k - 1, 0);
                t[i][k - 1][0] = lf;
            }
            if (t[k + 1][j][1] != -1)
            {
                rt = t[k + 1][j][1];
            }
            else
            {
                rt = solve(s, k + 1, j, 1);
                t[k + 1][j][1] = rt;
            }
            if (t[k + 1][j][0] != -1)
            {
                rf = t[k + 1][j][0];
            }
            else
            {
                rf = solve(s, k + 1, j, 0);
                t[k + 1][j][0] = rf;
            }

            if (s[k] == '&')
            {
                if (isTrue)
                {
                    ans = (ans + lt * rt) % 1003;
                }
                else
                {
                    ans = (ans + (lf * rt) + (lf * rf) + (lt * rf)) % 1003;
                }
            }
            else if (s[k] == '|')
            {
                if (isTrue)
                {
                    ans = (ans + (lt * rt) + (lt * rf) + (lf * rt)) % 1003;
                }
                else
                {
                    ans = (ans + (lf * rf)) % 1003;
                }
            }
            else if (s[k] == '^')
            {
                if (isTrue)
                {
                    ans = (ans + (lf * rt) + (lt * rf)) % 1003;
                }
                else
                {
                    ans = (ans + (lt * rt) + (lf * rf)) % 1003;
                }
            }
        }
        return t[i][j][isTrue] = ans;
    }

    int countWays(int n, string s)
    {
        // code here
        memset(t, -1, sizeof(t));
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

/*
To determine the time complexity of the given code, let's break down the logic and the nested recursive calls in the `solve` function.

The code is solving the Boolean Parenthesization problem using dynamic programming and memoization. The primary focus is on the `solve` function, which has the following key points:

1. **Recursive Structure**: The function is recursively dividing the problem at each operator and solving for both true and false outcomes on either side of the operator.
2. **Memoization**: The results of subproblems are stored in a 3-dimensional array `t` to avoid recomputation.

### Analysis of the `solve` Function

- The function considers every operator in the string (`k` loop), and for each operator, it recursively solves for the left and right parts of the string.
- Each subproblem is characterized by three parameters: the start index `i`, the end index `j`, and the boolean `isTrue`.

### Time Complexity

1. **Subproblem Count**:
   - The `solve` function can be called with any combination of `i`, `j`, and `isTrue`.
   - `i` can range from `0` to `n-1`.
   - `j` can range from `0` to `n-1` but must satisfy `i < j`.
   - `isTrue` can be either `0` or `1`.

   Thus, there are approximately `O(n^2 * 2)` subproblems (since `i` and `j` are `O(n)` and `isTrue` is 2).

2. **Time per Subproblem**:
   - For each subproblem, the loop over `k` runs approximately `O(n)` times, where `n` is the length of the string.
   - Inside the loop, each recursive call checks the memoization table, and performs constant-time operations otherwise.

Combining these, the overall time complexity can be calculated as follows:

\[ \text{Total time complexity} = \text{Number of subproblems} \times \text{Time per subproblem} \]
\[ \text{Total time complexity} = O(n^2 \times 2) \times O(n) \]
\[ \text{Total time complexity} = O(n^3) \]

Therefore, the time complexity of the given code is \( O(n^3) \).

### Space Complexity

The space complexity is determined by the memoization table and the call stack depth:

1. **Memoization Table**:
   - The memoization table `t` is a 3D array of size `n x n x 2`, resulting in a space complexity of `O(n^2 * 2) = O(n^2)`.

2. **Call Stack**:
   - The maximum depth of the recursive call stack is `O(n)`.

Therefore, the space complexity is \( O(n^2) \).

### Summary
- **Time Complexity**: \( O(n^3) \)
- **Space Complexity**: \( O(n^2) \)

These complexities arise from the efficient use of dynamic programming and memoization to solve overlapping subproblems and avoid redundant computations.
*/