class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> prev;
        prev[nums[0]]++;
        prev[-nums[0]]++;

        for (int i = 1; i < nums.size(); i++) {
            unordered_map<int, int> curr;        
            for (auto& p : prev) {
                curr[p.first+nums[i]] += p.second;
                curr[p.first-nums[i]] += p.second;
            }
            prev = curr;
        }

        return prev[target];
    }
};

// 2 1     3
// -2 1   -1
// -2 -1   -3
// 2 -1    1


// 2 -2
// 3 -1 
