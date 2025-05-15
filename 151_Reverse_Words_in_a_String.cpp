class Solution {
public:
    string reverseWords(string s) {
        int idx = 0;
        // skip the leading space
        while (s[idx] == ' ') idx++;

        vector<string> words;
        string tmp, ans;
        while (idx < s.size()) {
            tmp = "";
            while (idx < s.size() && s[idx] != ' ') {
                tmp.push_back(s[idx]);
                idx++;
            }
            words.push_back(tmp);
            while (idx < s.size() && s[idx] == ' ') {
                idx++;
            }
        }

        for (int i = words.size()-1; i >= 0; i--) {
            ans += words[i];
            if (i != 0) ans.push_back(' ');
        }
        return ans;
    }
};