class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int sum = nums[i] + nums[j];
                int l = j+1, r = n-1;
                int result = -1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (sum <= nums[mid]) {
                        r = mid - 1;
                    }
                    else if (sum > nums[mid]) {
                        l = mid + 1;
                        result = max(result, mid);
                    }
                }
                if (result != -1) ans += result - j;
            }
        }
        return ans;
    }
};

// the sum of any two side is larger than the third side

// sort
// pick i, j
// nums[i]+nums[j] = sum
// use binary search to find the largest element smaller than sum

// 2 3 4 4
// 2 3: 2
// 2 4: 1
// 3 4: 1
