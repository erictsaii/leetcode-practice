class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            vector<vector<int>> m(82);
            int tmp;
            int cnt, ans = -1, to_be_replace;
    
            for (int i = 0; i < nums.size(); i++) {
                cnt = 0;
                tmp = nums[i];
                while(tmp != 0) {
                    cnt += tmp % 10;
                    tmp /= 10;
                }
    
                if (m[cnt].size() <= 1) m[cnt].push_back(nums[i]);
                else {
                    to_be_replace = (m[cnt][0] < m[cnt][1]) ? 0 : 1;
                    m[cnt][to_be_replace] = max(m[cnt][to_be_replace], nums[i]);
                }
            }
    
            for (auto &x : m) {
                if (x.size() >= 2) {
                    ans = max(ans, x[0] + x[1]);
                }
            }
    
            return ans;
        }
    };