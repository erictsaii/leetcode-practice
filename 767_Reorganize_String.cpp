class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        for (auto& c : s) freq[c-'a']++;

        char prev = '#';
        string ans;
        for (int i = 0; i < s.size(); i++) {
            char to_push = '0';
            int max_freq = 0;

            for (int j = 0; j < 26; j++) {
                if (freq[j] > max_freq && 'a' + j != prev) {
                    max_freq = freq[j];
                    to_push = 'a' + j;
                }
            }

            if (to_push != '0') {
                ans.push_back(to_push);
                freq[to_push - 'a']--;
                prev = to_push;
            }
        }

        return (ans.size()==s.size()) ? ans : "";
    }
};
