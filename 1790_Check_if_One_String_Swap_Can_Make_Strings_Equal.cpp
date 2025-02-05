class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        vector<int> v(26, 0);
        
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                cnt++;
                v[s1[i] - 'a']++;
                v[s2[i] - 'a']--;
            }
        }
        if (cnt > 2) return false;

        for (auto i: v) {
            if (i != 0) return false;
        }
        return true;
    }
};
