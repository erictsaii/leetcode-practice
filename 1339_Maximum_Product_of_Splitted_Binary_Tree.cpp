/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long ans = 0;
    int sum;

    int total(TreeNode* root) {
        if (!root) return 0;
        int result = root->val;
        result += total(root->left);
        result += total(root->right);
        return result;
    }

    int solve(TreeNode* root) {
        int left = 0, right = 0;
        if (root->left) left = solve(root->left);
        if (root->right) right = solve(root->right);
        int sub_tree_sum = left + right + root->val;

        ans = max(ans, 1LL * sub_tree_sum * (sum - sub_tree_sum));
        return sub_tree_sum;
    }

    int maxProduct(TreeNode* root) {
        sum = total(root);
        solve(root);
        return ans % (int)(1e9+7);
    }
};

// calculate the sum of whole tree first
// post-order traverse
