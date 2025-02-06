class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                m[nums[i] * nums[j]]++;
            }
        }
        int ans = 0;
        for (auto it: m) {
            if (it.second >= 2) {
                ans += it.second * (it.second-1) * 4; 
            }
        }
        return ans;
    }
};
