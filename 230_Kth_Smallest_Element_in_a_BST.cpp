class Solution {
public:
    int ans = -1;
    void dfs(TreeNode* root, int& n) {
        if (root == nullptr) return;
        dfs(root->left, n);
        if (n == 1) ans = root->val;
        n--;
        dfs(root->right, n);
    }
    int kthSmallest(TreeNode* root, int k) {
        int n = k;
        dfs(root, n);
        return ans;
    }
};
