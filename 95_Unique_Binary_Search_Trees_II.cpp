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
    vector<TreeNode*> generate_trees(int start, int end) {
        if (start > end) return {nullptr};

        vector<TreeNode*> roots;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = generate_trees(start, i-1);
            vector<TreeNode*> right = generate_trees(i+1, end);
            
            for (auto& l : left) {
                for (auto& r : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    roots.push_back(root);
                }
            }
        }
        return roots;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generate_trees(1, n);
    }
};


// binary search tree: the left child is smaller than root, the right child is larger than root
// create all possible push order into the tree
// how to avoid duplicated tree?
