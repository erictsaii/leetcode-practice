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
    TreeNode* ans;

    void dfs(TreeNode* root, int p, int q) {
        if (!root) return;
        if (root->val > p && root->val > q) {
            dfs(root->left, p, q);
        }
        else if (root->val < p && root->val < q) {
            dfs(root->right, p, q);
        }
        else ans = root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p->val, q->val);
        return ans;    
    }
};
