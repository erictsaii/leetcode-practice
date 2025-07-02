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
using ull = unsigned long long;
class Solution {
public:
    vector<ull> v;  // min 
    ull ans = 0;

    void dfs(TreeNode* root, ull index, int depth) {
        if (!root) return;
        if (v.size() == depth) {
            v.push_back(index);
        }
        else {
            v[depth] = min(v[depth], index);
        }
        ans = max(ans, index - v[depth] + 1);
        dfs(root->left, 2*index , depth+1);
        dfs(root->right, 2*index + 1, depth+1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 0, 0);
        return ans;
    }
};
