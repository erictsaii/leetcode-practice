class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;

        for (auto& num : nums) {
            cnt[num]++;
        }

        priority_queue<pair<int, int>> pq; // freq, val
        for (auto& i : cnt) {
            pq.push({-i.second, i.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
