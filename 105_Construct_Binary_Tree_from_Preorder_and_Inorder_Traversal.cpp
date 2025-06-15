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
    unordered_map<int, int> m;
    TreeNode* build(int& pos, vector<int>& preorder, int start, int end) {
        if (start > end) return nullptr;
        int val = preorder[pos++];
        TreeNode* node = new TreeNode(val);

        node->left = build(pos, preorder, start, m[val]-1);
        node->right = build(pos, preorder, m[val]+1, end);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++){
            m[inorder[i]] = i;
        }
        int pos = 0;
        return build(pos, preorder, 0, preorder.size()-1);
    }
};
