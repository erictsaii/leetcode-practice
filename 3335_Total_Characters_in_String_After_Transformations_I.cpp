class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> cnt(26, 0);
        int MOD = 1e9+7;

        for (auto& c : s) cnt[c-'a']++;
        for (int i = 0 ; i < t; i++) {
            vector<int> next(26);
            next[0] = cnt[25];
            next[1] = (cnt[25] + cnt[0]) % MOD;
                
            for (int j = 2; j < 26; j++) {
                next[j] = cnt[j-1];
            }
            cnt = next;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += cnt[i];
            ans %= MOD;
        }
        return ans;
    }
};

// a + 25 -> z
// z + 1 -> ab

// for "a" + 26 -> "ab"  2
// "ab" + 26 -> "abbc"   4
// "abbc" + 26 -> "abbcbccd" 8
// "abbcbccd" + 26 -> "abbcbccdbccdcdde" 16

// return the "length" only
// pure math