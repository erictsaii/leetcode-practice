class Solution {
public:
    int subarray_at_most_k(vector<int>& nums, int k) {
        int start = 0;
        unordered_map<int, int> m;
        int result = 0;

        for (int end = 0; end < nums.size(); end++) {
            m[nums[end]]++;

            while (m.size() > k) {
                m[nums[start]]--;
                if (m[nums[start]] == 0) m.erase(nums[start]);
                start++;
            }

            result += end - start + 1;
        }
        return result;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarray_at_most_k(nums, k) - subarray_at_most_k(nums, k-1);
    }
};

// 1 + 2 + 3 + 4 + 2 = 12 
// 12 - 5 = 7
