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
    void dfs(TreeNode* root, TreeNode* parent, int key) {
        if (root->val == key) {
            if (!root->left && !root->right) { // has no child node
                if (parent->left == root) parent->left = nullptr;
                else parent->right = nullptr;
            }
            else if (!root->left&&root->right || root->left&&!root->right) { // has one child node
                TreeNode* child = (root->left) ? root->left : root->right;
                if (parent->left == root) parent->left = child;
                else parent->right = child;
            }
            else { // has two child nodes
                TreeNode* left_most_from_right_tree = root->right;
                while (left_most_from_right_tree->left != nullptr) left_most_from_right_tree = left_most_from_right_tree->left;
                root->val = left_most_from_right_tree->val;
                dfs(root->right, root, left_most_from_right_tree->val);
            }
        }
        else {
            if (root->left && root->val > key) dfs(root->left, root, key);
            if (root->right && root->val < key) dfs(root->right, root, key);
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        TreeNode *dummy = new TreeNode();
        dummy->left = root;
        dfs(root, dummy, key);
        return dummy->left;
    }
};