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
    vector<TreeNode*> ans;
    unordered_set<int> s;

    TreeNode* solve(TreeNode* root) {
        if (!root) return nullptr;
        
        root->left = solve(root->left);
        root->right = solve(root->right);

        if (s.count(root->val)) {
            if (root->left) ans.push_back(root->left);
            if (root->right) ans.push_back(root->right);
            delete root;
            return nullptr;
        }

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (auto& i : to_delete) s.insert(i);
        TreeNode* head = solve(root);
        if (head) ans.push_back(head);
        return ans;
    }
};

// distinct
