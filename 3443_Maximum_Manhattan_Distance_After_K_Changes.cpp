class Solution {
public:
    int maxDistance(string s, int k) {
        vector<int> cnt(4, 0); // N, S, E, W
        unordered_map<char, int> m;
        m['N'] = 0;
        m['S'] = 1;
        m['E'] = 2;
        m['W'] = 3;

        int ans = 0;
        for (auto& c : s) {
            cnt[m[c]]++;

            int dis, remain;
            dis = max(cnt[0], cnt[1]);
            remain = min(cnt[0], cnt[1]);

            dis += max(cnt[2], cnt[3]);
            remain += min(cnt[2], cnt[3]);

            dis += min(k, remain);
            dis -= max(0, remain - k);
            
            ans = max(ans, dis);
        }

        return ans;
    }
};
