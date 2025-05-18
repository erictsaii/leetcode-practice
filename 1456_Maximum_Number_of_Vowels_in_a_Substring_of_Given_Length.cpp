class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_map<char, bool> m;
        m['a'] = true;
        m['e'] = true;
        m['i'] = true;
        m['o'] = true;
        m['u'] = true;
        int ans = -1;
        int now = 0;
        for (int i = 0; i < k; i++) {
            if (m.find(s[i]) != m.end()) now++;
        }
        ans = max(ans, now);
        for (int i = k; i < s.size(); i++) {
            if (m.find(s[i]) != m.end()) now++;
            if (m.find(s[i-k]) != m.end()) now--;
            ans = max(ans, now);
        }

        return ans;
    }
};