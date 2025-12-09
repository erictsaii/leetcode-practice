class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> right;
        unordered_map<int, int> left;

        for (int i = 1; i < nums.size(); i++) right[nums[i]]++;

        int ans = 0;
        int MOD = 1e9+7;
        for (int i = 0; i < nums.size()-1; i++) {
            int target = nums[i] * 2;
            ans = (ans + (1LL * left[target] * right[target]) % MOD) % MOD;

            left[nums[i]]++;
            right[nums[i+1]]--;
        }     
        return ans;
    }
};

// contains 0

// fix j
// given nums[j] -> find left and right whose value is nums[j]*2 -> left_cnt * right_cnt 
// 
