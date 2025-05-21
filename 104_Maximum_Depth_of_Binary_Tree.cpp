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
    void dfs(TreeNode* root, int depth) {
        if (root->left) dfs(root->left, depth+1);
        if (root->right) dfs(root->right, depth+1);
        ans = max(ans, depth);
    }
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        dfs(root, 1);
        return ans;
    }
};