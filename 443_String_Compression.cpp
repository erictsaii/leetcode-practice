class Solution {
public:
    void write_chars(vector<char>& chars, int& idx, int prev, int cnt) {
        if (cnt == 1) chars[idx++] = prev;
        else {
            chars[idx++] = prev;
            string s_cnt = to_string(cnt);
            for (auto c : s_cnt) chars[idx++] = c;
        }
    }
    int compress(vector<char>& chars) {
        int idx = 0;
        int cnt = 1;
        char prev = chars[0];
        for (int i = 1; i < chars.size(); i++) {
            if (prev == chars[i]) {
                cnt++;
            }
            else {
                // write
                write_chars(chars, idx, prev, cnt);
                // update
                prev = chars[i];
                cnt = 1;
            }
        }
        // write the last group
        write_chars(chars, idx, prev, cnt);

        chars.resize(idx);
        return chars.size();
    }
};