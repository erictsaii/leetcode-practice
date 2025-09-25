class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int start = 0;
        deque<int> min_q, max_q;

        int ans = 0;
        for (int end = 0; end < nums.size(); end++) {
            // min_q -> non-decreasing
            while (min_q.size() && min_q.back() > nums[end]) {
                min_q.pop_back();
            }
            // max_q -> non-increasing
            while (max_q.size() && max_q.back() < nums[end]) {
                max_q.pop_back();
            }

            min_q.push_back(nums[end]);
            max_q.push_back(nums[end]);

            while (max_q.front() - min_q.front() > limit) {
                if (max_q.front() == nums[start]) {
                    max_q.pop_front();
                }
                if (min_q.front() == nums[start]) {
                    min_q.pop_front();
                }
                start++;
            }
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};
