/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> p_v;
    vector<TreeNode*> q_v;

    void dfs(TreeNode* root, vector<TreeNode*>& v, TreeNode* target, int to_find) {
        v.push_back(root);
        if (root->val == target->val) {
            if (to_find == 0) p_v = v;
            else q_v = v;
        }
        else {
            if (root->left) dfs(root->left, v, target, to_find);
            if (root->right) dfs(root->right, v, target, to_find);
        }
        v.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v;
        dfs(root, v, p, 0);
        dfs(root, v, q, 1);

        int i = 0;
        for (i = 0; i < min(p_v.size(), q_v.size()); i++) {
            if (p_v[i]->val != q_v[i]->val) break;
        }

        return p_v[i-1];
    }
};