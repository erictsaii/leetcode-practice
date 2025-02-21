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
class FindElements {
    public:
        TreeNode* _root;
        void recover (TreeNode* now) {
            if (now->left != nullptr) {
                now->left->val = now->val * 2 + 1;
                recover(now->left);
            }
            if (now->right != nullptr) {
                now->right->val = now->val * 2 + 2;
                recover(now->right);
            }
        }
        
        bool find_target (TreeNode* now, int target) {
            if (now == nullptr) return false;
            if (now->val == target) return true;
            return find_target(now->left, target) || find_target(now->right, target);
        }
    
        FindElements(TreeNode* root) {
            _root = root;
            root->val = 0;
            recover(root);
        }
        
        bool find(int target) {
            return find_target(_root, target);
        }
    };
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */