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
    void find_path(TreeNode* root, int val, string& s, string& tmp) {
        if (root->val == val) {
            s = tmp;
            return;
        }

        if (root->left) {
            tmp.push_back('L');
            find_path(root->left, val, s, tmp);
            tmp.pop_back();
        }

        if (root->right) {
            tmp.push_back('R');
            find_path(root->right, val, s, tmp);
            tmp.pop_back();
        }
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s_path, d_path, tmp;
        find_path(root, startValue, s_path, tmp);
        find_path(root, destValue, d_path, tmp);
        
        int idx = 0;
        while (s_path[idx] == d_path[idx]) idx++;
        s_path = s_path.substr(idx);
        d_path = d_path.substr(idx);

        return string(s_path.size(), 'U') + d_path;
    }
};
