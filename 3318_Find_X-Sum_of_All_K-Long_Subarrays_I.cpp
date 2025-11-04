class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> freq(51, 0);

        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (i < k-1) {
                freq[nums[i]]++;
                continue;
            }

            freq[nums[i]]++;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            for (int j = 0; j < 51; j++) {
                if (freq[j]) pq.push({freq[j], j});
                if (pq.size() > x) pq.pop();
            }

            int cnt = 0;
            while (pq.size()) {
                cnt += pq.top().first * pq.top().second;
                pq.pop();
            }
            ans.push_back(cnt);
            freq[nums[i-k+1]]--;
        }
        return ans;
    }
};

// for each subarray, we calculate all the occurrences (could be optimized by sliding window)
// keep the top x most frequent elements (prority queue), sum up

// O(n*xlogx)
