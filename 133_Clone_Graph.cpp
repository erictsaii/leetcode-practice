/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(vector<Node*>& nodes, Node* root) {

        for (auto& neighbor : root->neighbors) {
            if (nodes[neighbor->val] == nullptr) {
                nodes[neighbor->val] = new Node(neighbor->val);
                nodes[root->val]->neighbors.push_back(nodes[neighbor->val]);
                dfs(nodes, neighbor);
            }
            else {
                nodes[root->val]->neighbors.push_back(nodes[neighbor->val]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        vector<Node*> nodes(101, nullptr);
        nodes[node->val] = new Node(node->val);
        
        dfs(nodes, node);

        return nodes[node->val];
    }
};
