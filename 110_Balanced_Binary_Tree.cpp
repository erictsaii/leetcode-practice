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
    bool ans = true;

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int left_height = dfs(root->left);
        int right_height = dfs(root->right);

        if (abs(left_height - right_height) > 1) ans = false;

        return max(left_height, right_height) + 1;
    }

    bool isBalanced(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
