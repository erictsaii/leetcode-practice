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
        int pos = 0;
        void recover(TreeNode* root, int depth, string& traversal) {
            // cal dash_length
            int dash_length = 0;
            while (pos < traversal.size() && !isdigit(traversal[pos])) {
                dash_length++;
                pos++;
            }
    
            // left first
            if (dash_length == depth + 1) {
                // cal left number
                int num = 0;
                while (isdigit(traversal[pos])) {
                    num *= 10;
                    num += traversal[pos] - '0';
                    pos++;
                }
                TreeNode* left_node = new TreeNode(num);
                root->left = left_node;
                recover(root->left, depth+1, traversal);
            }
            else {
                pos -= dash_length;
                return;
            }
    
            // cal dash_length
            dash_length = 0;
            while (pos < traversal.size() && !isdigit(traversal[pos])) {
                dash_length++;
                pos++;
            }
    
            // right
            if (dash_length == depth + 1) {
                // cal right number
                int num = 0;
                while (isdigit(traversal[pos])) {
                    num *= 10;
                    num += traversal[pos] - '0';
                    pos++;
                }
                TreeNode* right_node = new TreeNode(num);
                root->right = right_node;
                recover(root->right, depth+1, traversal);
            }
            else {
                pos -= dash_length;
                return;
            }
        }
        TreeNode* recoverFromPreorder(string traversal) {
            int num = 0;
            while (isdigit(traversal[pos])) {
                num *= 10;
                num += traversal[pos] - '0';
                pos++;
            }
            TreeNode* root = new TreeNode(num);
            recover(root, 0, traversal);
    
            return root;
        }
    };