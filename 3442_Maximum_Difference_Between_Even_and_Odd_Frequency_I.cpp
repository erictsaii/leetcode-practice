class Solution {
public:
    int maxDifference(string s) {
        vector<int> cnt(26, 0);
        int max_odd = 0, min_even = 100;
        
        for (auto&c : s) cnt[c - 'a']++;
        
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) continue;
            if (cnt[i] % 2) {
                max_odd = max(max_odd, cnt[i]);
            }
            else {
                min_even = min(min_even, cnt[i]);
            }
        }

        return max_odd - min_even;
    }
};
