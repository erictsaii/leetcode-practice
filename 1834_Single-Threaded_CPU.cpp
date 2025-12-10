class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<pair<int, int>> v; // enqueue_time, original_index
        for (int i = 0; i < tasks.size(); i++) {
            v.push_back({tasks[i][0], i});
        }
        sort(v.begin(), v.end());

        int min_enqueue_time = v[0].first;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // min_heap -> processing_time, index
        int pos = 0;
        for (; pos < v.size(); pos++) {
            if (v[pos].first == min_enqueue_time) pq.push({tasks[v[pos].second][1], v[pos].second});
            else break;
        }

        long long time = v[0].first;
        vector<int> ans;
        while (pq.size()) {
            auto [processing_time, index] = pq.top();
            pq.pop();
            time += processing_time;
            ans.push_back(index);

            for (; pos < v.size(); pos++) {
                if (v[pos].first <= time) pq.push({tasks[v[pos].second][1], v[pos].second});
                else break;
            }

            if (pq.empty() && pos < v.size()) {
                time = v[pos].first;
                for (; pos < v.size(); pos++) {
                    if (v[pos].first <= time) pq.push({tasks[v[pos].second][1], v[pos].second});
                    else break;
                }  
            }
        }
        return ans;
    }
};
