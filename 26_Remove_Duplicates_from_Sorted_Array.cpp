class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p1 = 0, p2 = 0;
        int n = nums.size();
        while (p2 < n) {
            while (p2+1 < n && nums[p2] == nums[p2+1]) p2++;
            nums[p1] = nums[p2];
            p1++;
            p2++;
        }
        return p1;
    }
};
