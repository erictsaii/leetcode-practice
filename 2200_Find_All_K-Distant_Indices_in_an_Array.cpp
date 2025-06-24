class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<bool> is_k_distance(n, false);

        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                for (int j = max(0, i-k); j < min(n, i+k+1); j++) {
                    is_k_distance[j] = true;
                }
            }
        }
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (is_k_distance[i]) ans.push_back(i);
        }

        return ans;
    }
};
