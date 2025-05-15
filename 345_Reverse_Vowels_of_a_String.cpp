class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, r = s.size()-1;
        unordered_map <char, bool> m;
        m['a'] = true;
        m['e'] = true;
        m['i'] = true;
        m['o'] = true;
        m['u'] = true;

        while (l < r) {
            while (l<r && m.find(tolower(s[l])) == m.end()) l++;
            while (l<r && m.find(tolower(s[r])) == m.end()) r--;
            if (l < r) swap(s[l], s[r]);
            l++;
            r--;
        }
        return s;
    }
};