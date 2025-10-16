class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> v(value, 0); // record the freq of each remainder

        for (auto& num : nums) {
            v[((num % value) + value) % value]++;
        }

        int ans = 0;
        while (v[ans % value]) {
            v[ans % value] --;
            ans++;
        }
        return ans;
    }
};

// we should make the array looks like 0 1 2 3 ...
// group nums by the remainder
