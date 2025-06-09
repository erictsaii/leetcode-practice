class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, bool> m;
        int ans = 0;
        int start = 0;
        
        for (int end = 0; end < s.size(); end++) {
            while (m.find(s[end]) != m.end()) {
                m.erase(s[start]);
                start++;
            }
            m[s[end]] = true;
            ans = max(ans, end - start + 1);
        }

        return ans;
    }
};
