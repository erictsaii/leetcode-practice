class Solution {
    public:
        int numberOfSubstrings(string s) {
            int left = 0, right = 0, ans = 0;
            unordered_map<char, int> m;
            while (right < s.size()) {
                m[s[right]]++;
    
                while (m.size() == 3 && left < right) {
                    ans += s.size() - right;
                    m[s[left]]--;
                    if (m[s[left]] == 0) m.erase(s[left]);
                    left++;
                }
                right++;
            } 
    
            return ans;
        }
    };