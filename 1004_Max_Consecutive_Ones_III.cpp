class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt = 0;
        int ans = 0;
        int start = 0;

        for (int end = 0; end < nums.size(); end++) {
            if (nums[end] == 0) cnt++;
            while (cnt > k) {
                if (nums[start++]==0) cnt--; 
            }
            ans = max(ans, end-start+1);
        }

        return ans;
    }
};