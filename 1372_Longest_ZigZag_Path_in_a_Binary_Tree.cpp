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
    int ans = 0;
    // -1 for left, 1 for right
    void dfs(TreeNode* root, int prev_dir, int len) {
        ans = max(ans, len);

        if (root->left) {
            if (prev_dir == -1) dfs(root->left, -1, 1);
            else if (prev_dir == 1) dfs(root->left, -1, len+1);
        }

        if (root->right) {
            if (prev_dir == 1) dfs(root->right, 1, 1);
            else if (prev_dir == -1) dfs(root->right, 1, len+1);
        }
    }
    int longestZigZag(TreeNode* root) {
        dfs(root, 1, 0);
        dfs(root, -1, 0);
        return ans;
    }
};