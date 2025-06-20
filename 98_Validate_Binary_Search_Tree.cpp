class Solution {
public:
    long long last = LONG_LONG_MIN;
    bool ans = true;
    bool dfs(TreeNode* root, long max_val, long min_val){
        if (!root) return true;
        if (root->val >= max_val || root->val <= min_val) return false;
        return dfs(root->left, root->val, min_val) && dfs(root->right, max_val, root->val);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MAX, LONG_MIN);
    }
};
