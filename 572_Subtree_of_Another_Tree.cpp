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
    bool ans = false;

    bool is_valid(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (!root || !subRoot) return false;
        if (root->val != subRoot->val) return false;

        return is_valid(root->left, subRoot->left) && is_valid(root->right, subRoot->right);
    }

    void dfs(TreeNode* root, TreeNode* subRoot) {
        if (!root) return;
        if (root->val == subRoot->val) {
            if (is_valid(root, subRoot)) ans = true;
        }
        dfs(root->left, subRoot);
        dfs(root->right, subRoot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        dfs(root, subRoot);
        return ans;
    }
};
