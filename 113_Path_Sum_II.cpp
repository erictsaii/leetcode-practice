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
    vector<vector<int>> ans;
    int t;

    void dfs(TreeNode* root, int sum, vector<int> v){
        if(!root->right && !root->left){
            if(sum==t) ans.push_back(v);
        }
        else{
            if(root->left) {
                v.push_back(root->left->val);    
                dfs(root->left,sum+root->left->val, v);
                v.pop_back();
            }
            if (root->right){
                v.push_back(root->right->val);
                dfs(root->right,sum+root->right->val, v);
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return ans;
        t=targetSum;
        dfs(root, root->val, {root->val});
        return ans;
    }
};
