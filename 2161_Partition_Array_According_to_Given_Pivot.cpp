class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            queue<int> less, equal, greater;
            for (auto &n : nums) {
                if (n > pivot) greater.push(n);
                else if (n == pivot) equal.push(n);
                else less.push(n);
            }
            int idx = 0;
            while(less.size() != 0) {
                nums[idx] = less.front();
                less.pop();
                idx++;
            }
            while(equal.size() != 0) {
                nums[idx] = equal.front();
                equal.pop();
                idx++;
            }
            while(greater.size() != 0) {
                nums[idx] = greater.front();
                greater.pop();
                idx++;
            }
    
            return nums;
        }
    };