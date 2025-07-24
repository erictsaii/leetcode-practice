class Solution {
public:
    int ans = 0;
    int even_right_left(int idx, vector<int>& cost) {
        if (idx > cost.size()) return 0;

        int left = even_right_left(2*idx, cost);
        int right = even_right_left(2*idx+1, cost);

        ans += abs(left - right);

        return cost[idx-1] + max(left, right);
    }

    int minIncrements(int n, vector<int>& cost) {
        even_right_left(1, cost);
        return ans;
    }
};
