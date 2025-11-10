class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> stk;

        int ans = 0;
        for (auto& num : nums) {
            while (stk.size() && stk.top() > num) {
                stk.pop();
            }
            if (num == 0) continue;
            if (stk.empty() || stk.top() < num) {
                ans++;
                stk.push(num);
            }
        }
        return ans;
    }
};
