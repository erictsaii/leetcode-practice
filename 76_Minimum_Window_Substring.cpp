class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> t_cnt(52, 0); // upper first, then lower
        vector<int> s_cnt(52, 0);

        for (auto&c : t) {
            if ('A' <= c && c <= 'Z') t_cnt[c-'A']++;
            else t_cnt[c-'a'+26]++;
        }

        int start = 0;
        int p1 = 0, p2 = s.size();
        int total = t.size();
        int now = 0;
        int i;

        for (int end = 0; end < s.size(); end++) {
            if ('A' <= s[end] && s[end] <= 'Z') {
                i = s[end] - 'A';
                s_cnt[i]++;
                if (s_cnt[i] <= t_cnt[i]) now++;
            }
            else {
                i = s[end] - 'a' + 26;
                s_cnt[i]++;
                if (s_cnt[i] <= t_cnt[i]) now++;
            }
            

            while (now == total) {
                if (p2 - p1 > end-start) {
                    p1 = start;
                    p2 = end;
                }

                if ('A' <= s[start] && s[start] <= 'Z') {
                    i = s[start] - 'A';
                    s_cnt[i]--;
                    if (s_cnt[i] < t_cnt[i]) now--;
                }
                else {
                    i = s[start] - 'a' + 26;
                    s_cnt[i]--;
                    if (s_cnt[i] < t_cnt[i]) now--;
                }
                start++;
            }
        }
        return (p2 == s.size()) ? "" : s.substr(p1, p2 - p1 + 1);
    }
};
