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
    int ans = 0;
    unordered_map<long long, int> m;

    void dfs(TreeNode* root, long long sum, int targetSum) {
        if (root) {
            sum += root->val;
            if (sum == targetSum) ans++;
            if (m.find(sum - targetSum) != m.end()) ans += m[sum-targetSum];
            m[sum]++;
            dfs(root->left, sum, targetSum);
            dfs(root->right, sum, targetSum);
            m[sum]--;
        }
    }

    int pathSum(TreeNode* root, int targetSum) {
        dfs(root, 0, targetSum);
        return ans;
    }
};