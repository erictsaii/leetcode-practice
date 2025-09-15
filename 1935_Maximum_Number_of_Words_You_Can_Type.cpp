class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> broken(26, false);

        for (auto&c : brokenLetters) {
            broken[c - 'a'] = true;
        }

        int broken_cnt = 0;
        int ans = 0;
        for (auto& c : text) {
            if (c == ' ') {
                if (broken_cnt == 0) ans++;
                broken_cnt = 0;
            }
            else {
                if (broken[c - 'a']) broken_cnt++;
            }
        }
        if (broken_cnt == 0) ans++;
        
        return ans;
    }
};
