/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* build(vector<vector<int>>& grid, int y, int x, int len) {
        // check if the whole block contains only 0 or 1
        int cnt = 0;
        for (int i = y; i < y+len; i++) {
            for (int j = x; j < x+len; j++) {
                if (grid[i][j]) cnt++;
            }
        }        

        if (cnt == 0 || cnt == len*len) {
            Node* root = new Node();
            root->isLeaf = true;
            root->val = (cnt) ? true : false;
            return root;
        }

        int nxt_len = len / 2;
        Node* top_left = build(grid, y, x, nxt_len);
        Node* top_right = build(grid, y, x+nxt_len, nxt_len);
        Node* bottom_left = build(grid, y+nxt_len, x, nxt_len);
        Node* bottom_right = build(grid, y+nxt_len, x+nxt_len, nxt_len);

        Node* root = new Node(true, false, top_left, top_right, bottom_left, bottom_right);
        return root;
    }

    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }
};
