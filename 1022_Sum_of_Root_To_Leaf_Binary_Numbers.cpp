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

    void dfs(TreeNode* root, int curr_sum) {
        if (!root->left && !root->right) {
            ans += curr_sum;
            return;
        }

        curr_sum *= 2;
        
        if (root->left) dfs(root->left, curr_sum + root->left->val);
        if (root->right) dfs(root->right, curr_sum + root->right->val);
    }

    int sumRootToLeaf(TreeNode* root) {
        dfs(root, root->val);
        return ans;
    }
};
