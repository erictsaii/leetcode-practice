class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int dominant = nums[0], cnt = 1;
    
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] == dominant) cnt++;
                else cnt--;
                if (cnt == 0) {
                    dominant = nums[i];
                    cnt = 1;
                }
            }
            int total = 0;
            for (int i = 0; i < nums.size(); i++) if (nums[i] == dominant) total++;
    
            cnt = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == dominant) cnt++;
                if ((cnt*2 > i+1) && (total-cnt)*2 > (nums.size()-i-1)) return i;
            }
    
            return -1;
        }
    };
    