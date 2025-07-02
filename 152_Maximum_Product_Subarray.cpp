class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product = 0;
        int start = 0;
        int ans = INT_MIN;
        for (auto& num : nums) ans = max(ans, num);
        nums.push_back(0);

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {  
                while(product < 0 && start < i - 1) {
                    product /= nums[start];
                    start++;
                }
                ans = max(ans, product);
                product = 0;
                start = i+1;
            }
            else {
                if (product == 0) product = nums[i];
                else product *= nums[i];
                ans = max(ans, product);
            }
        }

        return ans;
    }
};
