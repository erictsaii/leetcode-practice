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
        TreeNode* dfs(unordered_map<int, int>& m, vector<int>& postorder, int& pos) {
            int now = pos;
            TreeNode* node = new TreeNode(postorder[now]);
            pos--;
            
            if ((pos >= 0) && (m[postorder[now]] < m[postorder[pos]])) {
                node->right = dfs(m, postorder, pos);
            }
            if ((pos >= 0) && (m[postorder[now]] < m[postorder[pos]])) {
                node->left = dfs(m, postorder, pos);
            }
            return node;
        }
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            unordered_map<int, int> m; // num, idx
            int pos = postorder.size()-1;
    
            for (int i = 0; i < preorder.size(); i++) {
                m[preorder[i]] = i;
            }
    
            return dfs(m, postorder, pos);
        }
    };