#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    int helper(TreeNode *root, int &maxi)
    {
        if (root == NULL)
            return 0;

        int l = helper(root->left, maxi);
        int r = helper(root->right, maxi);

        int temp = max(max(l, r) + root->val, root->val);
        int ans = max(temp, l + r + root->val);
        maxi = max(maxi, ans);

        return temp;
    }

    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        helper(root, maxi);
        return maxi;
    }
};

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