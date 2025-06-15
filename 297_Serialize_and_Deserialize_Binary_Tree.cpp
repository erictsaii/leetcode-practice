/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void pre(TreeNode* root, string& s) {
        if (!root) s.append("n ");
        else {
            s.append(to_string(root->val));
            s.append(" ");
            pre(root->left, s);
            pre(root->right, s);
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string preorder;

        pre(root, preorder);

        return preorder;
    }

    TreeNode* build(int& pos, vector<int> preorder) {
        if (preorder[pos] == 1001) {
            pos++;
            return nullptr;
        }
        
        TreeNode* node = new TreeNode(preorder[pos++]);
        node->left = build(pos, preorder);
        node->right = build(pos, preorder);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return nullptr;
        vector<int> preorder;
        
        int idx = 0;
        int sum;

        while (idx < data.size()) {
            if (data[idx] == 'n') {
                preorder.push_back(1001);
                idx += 2;
                continue;
            }
            int sign = 1; // 1 for positive
            sum = 0;

            if (data[idx] == '-') {
                sign = -1;
                idx++;
            }

            while (data[idx] != ' ') {
                sum *= 10;
                sum += data[idx] - '0';
                idx++;
            }
            idx++; // for blank
            preorder.push_back(sum * sign);
        }

        // now, we could construct binary tree by preorder with null specified
        int pos = 0;
        return build(pos, preorder);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
