class Solution {
public:
    bool valid(int guess, vector<int>& nums, int p) {
        int cnt = 0;

        int i;
        for (i = 0; i < nums.size()-1; i++) {
            if (abs(nums[i] - nums[i+1]) <= guess) {
                i++;
                cnt++;
            }
        }

        return cnt >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int l = 0, r = nums[n-1] - nums[0];
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (valid(mid, nums, p)) {
                r = mid - 1;
                ans = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

// 先sort

// 1 2 2 4
//  1 0 2

// 1 1 2 3 7 10
//  0 1 1 4 3

// 1 2 2 2 3 3 4
//  1 0 0 1 0 1
