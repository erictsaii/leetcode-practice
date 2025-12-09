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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool seen_null = false;
        while (q.size()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto curr_node = q.front();
                q.pop();
                if (curr_node && seen_null) return false;

                if (!curr_node) seen_null = true;
                else {
                    q.push(curr_node->left);
                    q.push(curr_node->right);
                }
            }
        }
        return true;
    }
};

// one iteration for one level
