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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int max_sum = INT_MIN;
        int ans = 0;
        int depth = 1;

        q.push(root);
        while (!q.empty()) {
            int sum = 0;
            int curr_size = q.size();

            for (int i = 0; i < curr_size; i++) {
                sum += q.front()->val;
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);
                q.pop();
            }

            if (sum > max_sum) {
                max_sum = sum;
                ans = depth;
            }
            depth++;
        }
        return ans;
    }
};