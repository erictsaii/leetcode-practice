class Solution {
public:
    vector<int> original;

    Solution(vector<int>& nums) {
        original = nums;
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        vector<int> ans = original;

        for (int i = 0; i < ans.size(); i++) {
            int random_index = rand() % ans.size();
            swap(ans[i], ans[random_index]);
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
