class Solution {
    public:
        bool valid(vector<int>& nums, int k, int val) {
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= val){
                    cnt++;
                    i++;
                } 
                if (cnt == k) return true;
            }
            return false;
        }
        int minCapability(vector<int>& nums, int k) {
            int n = nums.size(), ans;
            vector<int> sorted(n);
            for (int i = 0; i < n; i++) sorted[i] = nums[i];
            sort(sorted.begin(), sorted.end());
    
            int l = 0, r = n, mid, val;
            while (l <= r) {
                mid = (l + r) / 2;
                val = sorted[mid];
                if (valid(nums, k, val)) {
                    ans = val;
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            return ans;
        }
    };
    
    