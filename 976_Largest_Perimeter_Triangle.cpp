class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());

        for (int i = 0; i < nums.size()-2; i++) {
            if (nums[i] < nums[i+1] + nums[i+2]) return nums[i]+nums[i+1]+nums[i+2];
        }
        return 0;
    }
};

// first, it has to be a triangle
// and we want the one with largest perimeter

// sort in the non-ascending order
// pick i i+1 i+2, and traverse
// if any of which form a triangle, return
// if we have traversed to the end, return 0
// O(nlogn)
