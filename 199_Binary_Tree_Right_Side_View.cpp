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
    vector<int> ans;

    void dfs(TreeNode* root, int depth) {
        if (ans.size() <= depth) ans.push_back(root->val);
        else ans[depth] = root->val;
        if (root->left) dfs(root->left, depth+1);
        if (root->right) dfs(root->right, depth+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        dfs(root, 0);
        return ans;
    }
};