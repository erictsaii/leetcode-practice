class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int target = 0;
        for (auto& num : nums) {
            target  = (target + num) % p;
        }

        unordered_map<int, int> m; // mod result -> largest index
        int curr_prefix = 0;
        int min_length = nums.size();
        m[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            curr_prefix += nums[i];
            curr_prefix %= p;

            m[curr_prefix] = i;

            int to_find = (curr_prefix + p - target) % p;
            if (m.count(to_find)) {
                min_length = min(min_length, i - m[to_find]);
            }
        }
        return (min_length == nums.size()) ? -1 : min_length;
    }
};


// it's not allow to remove the whole array
// remove samllest contiguous subarray to make the sum divisible by p


// all_sum % p == 1

// find smallest subarray, sub_sum %p == 1

// sum = 10
// 10 % 6 = 4

// 3 -> 4? we find if there exists a prefix whose val is 5
// memorize the largest index whose prefix_sum % p is x 
