class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> m; // ith day, prev_rain_idx  
        set<int> zeros_idx;
        vector<int> ans(n, 1);

        for (int i = 0; i < rains.size(); i++) {
            if (rains[i] == 0) {
                zeros_idx.insert(i);
                continue;
            }
            
            ans[i] = -1;
            if (m.count(rains[i])) {
                int prev_idx = m[rains[i]];
                auto it = zeros_idx.upper_bound(prev_idx); // find the first 0, whose idx is larger than prev_idx
                if (it == zeros_idx.end()) return {};
                
                ans[*it] = rains[i];
                zeros_idx.erase(it);
            }
            m[rains[i]] = i;
        }
        return ans;
    }
};

// when rains[i] != 0, I get a chance to decide which lake have to be dried
// find the closest lake which is behind zero and it's full
// naive find: O(n^2)
// 1 2 0 3 0 3 3 1 
// unordered_map<int, int> m; // ith day, prev_rain_idx  
