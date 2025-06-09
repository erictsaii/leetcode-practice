class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m; // val, idx
    
        for (int i = 0; i < nums.size(); i++) {
            int remain = target - nums[i];
            if (m.find(remain) != m.end()) return {m[remain], i};
            m[nums[i]] = i;
        }
        return {};
    }
};
