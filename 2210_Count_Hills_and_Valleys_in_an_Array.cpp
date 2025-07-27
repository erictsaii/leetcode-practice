class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0;
        int up = 0;
        int down = 0;

        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] > nums[i+1]) {
                down = 1;
                if (up && down) {
                    up = 0;
                    ans++;
                }
            }
            else if (nums[i] < nums[i+1]) {
                up = 1;
                if (up && down) {
                    down = 0;
                    ans++;
                }
            } 
        }

        return ans;
    }
};
