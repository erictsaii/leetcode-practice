class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // endtime, server num

        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        vector<int> cnt(k, 0);
        for (int i = 0; i < arrival.size(); i++) {
            while (pq.size() && pq.top().first <= arrival[i]) {
                available.insert(pq.top().second);
                pq.pop();
            }

            // try to find i % k to k-1
            auto it = available.lower_bound(i % k);
            if (it != available.end()) {
                pq.push({arrival[i] + load[i], *it});
                cnt[*it]++;
                available.erase(it);
                continue;
            }

            // try to find 0 to i % k-1
            it = available.lower_bound(0);
            if (it != available.end()) {
                pq.push({arrival[i] + load[i], *it});
                cnt[*it]++;
                available.erase(it);
            }
        }


        int max_val = *max_element(cnt.begin(), cnt.end());

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            if (cnt[i] == max_val) ans.push_back(i);
        }
        return ans;
    }
};


// if all busy, request is dropped
// assign to (i % k) first, if busy, assign to i+1...

// find busiest server


// naive: O(arrival.size() * k)

// use a pq to record all server's end time
// 分available跟不available
// O(arrival.size()*logk)
