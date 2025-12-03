class Solution {
public:

    int memo[20][20] = {0};

    int count_trees(int start, int end) {
        if (start > end) return 1;
        if (memo[start][end]) return memo[start][end];
        
        int cnt = 0;
        for (int i = start; i <= end; i++) {
            int left = count_trees(start, i-1);
            int right = count_trees(i+1, end);

            cnt += left * right;
        }
        return memo[start][end] = cnt;
    }

    int numTrees(int n) {
        return count_trees(1, n);
    }
};
