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
    unordered_map<string, int> subtrees;
    vector<TreeNode*> ans;

    string solve(TreeNode* root) {
        if (!root) return "#";

        string left = solve(root->left);
        string right = solve(root->right);
        string total = left + "," + right + "," + to_string(root->val);

        if (subtrees[total] == 1) {
            ans.push_back(root);
        }
        subtrees[total]++;
        return total;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        return ans;
    }
};
