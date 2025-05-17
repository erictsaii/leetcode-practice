class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int ans = -1;
        while (l < r) {
            ans = max(ans, (r-l) * min(height[l], height[r]));
            if (height[l] < height[r]) l++;
            else r--;
        }
        return ans;
    }
};

// 求 max((i-j) * min(height[i], height[j]))
// 觀察: height[i]較小的往內更新，才有機會會有更大的面積