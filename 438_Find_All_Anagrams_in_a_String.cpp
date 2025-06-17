class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> s_cnt(26, 0);
        vector<int> p_cnt(26, 0);

        for (auto& c : p) p_cnt[c - 'a']++;

        vector<int> ans;
        int start = 0;

        for (int end = 0; end < s.size(); end++) {
            if (end - start < p.size()-1) {
                s_cnt[s[end] - 'a']++;
                continue;
            }
            s_cnt[s[end] - 'a']++;

            if (s_cnt == p_cnt) ans.push_back(start);
            
            s_cnt[s[start] - 'a']--;
            start++;
        }

        return ans;
    }
};
