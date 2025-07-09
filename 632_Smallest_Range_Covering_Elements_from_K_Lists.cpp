class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<int> index(k, 0);
        int max_val = INT_MIN;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        for (int i = 0; i < k; i++) {
            max_val = max(max_val, nums[i][0]);
            pq.push({nums[i][0], i});
        }

        vector<int> ans(2);
        ans[0] = -1e6;
        ans[1] = 1e6;

        while (pq.size() == k) {
            int min_val = pq.top()[0], min_idx = pq.top()[1];
            pq.pop();
            if (max_val - min_val < ans[1] - ans[0]) {
                ans[0] = min_val;
                ans[1] = max_val;
            }
            index[min_idx]++;
            if (index[min_idx] < nums[min_idx].size()) {
                pq.push({nums[min_idx][index[min_idx]], min_idx});
                max_val = max(max_val, nums[min_idx][index[min_idx]]);
            }
        }

        return ans;
    }
};
