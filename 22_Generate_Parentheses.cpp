class Solution {
public:
    vector<string> ans;

    void backtrack(string now, int right, int left, int n) {
        if (now.size() == n*2) ans.push_back(now);
        else {
            if (right > 0) backtrack(now+'(', right-1, left+1, n);
            if (left > 0) backtrack(now+')', right, left-1, n);
        } 
    }

    vector<string> generateParenthesis(int n) {
        backtrack("", n, 0, n);

        return ans;
    }
};
