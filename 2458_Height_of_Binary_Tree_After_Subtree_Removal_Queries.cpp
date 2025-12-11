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
    int max_left[100005], max_right[100005];
    int max_height;

    void from_left(TreeNode* root, int height) {
        if (!root) return;
        max_left[root->val] = max_height;
        max_height = max(max_height, height);
        from_left(root->left, height+1);
        from_left(root->right, height+1);
    }

    void from_right(TreeNode* root, int height) {
        if (!root) return;
        max_right[root->val] = max_height;
        max_height = max(max_height, height);
        from_right(root->right, height+1);
        from_right(root->left, height+1);
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        max_height = 0;
        from_left(root, 0);
        max_height = 0;
        from_right(root, 0);

        vector<int> ans;
        for (auto& q : queries) {
            ans.push_back(max(max_left[q], max_right[q]));
        }
        return ans;
    }
};
