class Solution {
public:
    bool is_vowel(const char& c) {
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }

    int maxFreqSum(string s) {
        unordered_map<char, int> cnt;
        for (auto& c : s) {
            cnt[c]++;
        }

        int v_cnt = 0, c_cnt = 0;
        for (auto& i : cnt) {
            if (is_vowel(i.first)) v_cnt = max(v_cnt, i.second);
            else c_cnt = max(c_cnt, i.second);
        }

        return v_cnt + c_cnt;
    }
};
