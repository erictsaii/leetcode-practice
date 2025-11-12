class Solution {
public:
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a%b);
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int one_cnt = 0;
        for (auto& num : nums) {
            if (num == 1) one_cnt++;
        }
        if (one_cnt) return nums.size() - one_cnt;

        int result;
        for (int i = 0; i < n-1; i++) {
            result = gcd(nums[i], nums[i+1]);
            if (result == 1) return nums.size();
        }

        int min_length = INT_MAX;
        for (int i = 0; i < n; i++) {
            result = nums[i];
            for (int j = i+1; j < n; j++) {
                result = gcd(result, nums[j]);
                if (result == 1) {
                    min_length = min(min_length, j-i+1);
                    break;
                } 
            }
        } 

        return (min_length == INT_MAX) ? -1 : min_length + n - 2;
    }
};

// all positive integers

// for each operation:
// replace nums[i] or nums[i+1] with gcd(nums[i], nums[i+1])

// goal: make all element into 1
// return the minimum number of operations (-1 if not possible)
