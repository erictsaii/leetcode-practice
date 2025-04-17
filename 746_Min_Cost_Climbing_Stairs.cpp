class Solution {
    public:
        int dp(vector<int>& cost, vector<int>& memo, int n) {
            if (n >= cost.size()) return 0;
            if (memo[n] != -1) return memo[n];
            int one = cost[n] + dp(cost, memo, n+1);
            int two = cost[n] + dp(cost, memo, n+2);
    
            memo[n] = min(one, two);
            return memo[n];
        }
        int minCostClimbingStairs(vector<int>& cost) {
            vector<int> memo(cost.size()+1, -1);
            int zero = dp(cost, memo, 0);
            memo.resize(cost.size());
            int one = dp(cost, memo, 1);
    
            return min(zero, one);
        }
    };