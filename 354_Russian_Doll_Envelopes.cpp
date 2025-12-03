class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);

        vector<int> res;
        for (int i = 0; i < envelopes.size(); i++) {
            if (res.empty() || res.back() < envelopes[i][1]) {
                res.push_back(envelopes[i][1]);
            }
            else {
                auto it = lower_bound(res.begin(), res.end(), envelopes[i][1]);
                *it = envelopes[i][1];
            }
        }
        return res.size();
    }
};

// wi < wj && hi < hj

// [1,1] [2,3] [4,5] [4,6] [6,7] 
