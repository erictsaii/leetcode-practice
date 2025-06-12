class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> cnt;

        for (auto& c : s) cnt[c]++;

        int ans = 0;
        bool has_odd = false;
        for (auto& c : cnt) {
            if (c.second % 2) has_odd = true;
            if (c.second >= 2) {
                ans += (c.second / 2) * 2;
            }
        }

        if (has_odd) ans++;

        return ans;
    }
};
