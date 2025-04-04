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
        int max_depth = -1, max_depth_num = 0;
        TreeNode* ans = nullptr;
    
        void find_max_depth(TreeNode* root, int depth) {
            if (depth > max_depth) {
                max_depth = depth;
                max_depth_num = 1;
            }
            else if (depth == max_depth) {
                max_depth_num++;
            }
    
            if (root->left) find_max_depth(root->left, depth+1);
            if (root->right) find_max_depth(root->right, depth+1);
        }
    
        int find_lca(TreeNode* root, int depth) {
            if (!root) return 0;
            if (!root->left && !root->right) {
                return (depth == max_depth) ? 1 : 0;
            }
            int sum = find_lca(root->left, depth+1) + find_lca(root->right, depth+1);
            if (sum == max_depth_num && ans == nullptr) ans = root;
            return sum;
        }
        
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            if (!root->right && !root->left) return root;
            find_max_depth(root, 0);
            find_lca(root, 0);
            if (max_depth_num == 1) ans = (ans->left) ? ans->left : ans->right;
            return ans;   
        }
    };