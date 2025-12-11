class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<vector<string>> possible_sentences(n+1);

        possible_sentences[0].push_back("");

        for (int i = 1; i <= s.size(); i++) {
            for (auto& word : wordDict) {
                int len = word.size();
                if (i - len < 0) continue;
                string tmp = s.substr(i - len, len);
                if (tmp == word) {
                    for (auto& prev_s : possible_sentences[i-len]) {
                        if (prev_s == "") possible_sentences[i].push_back(word);
                        else possible_sentences[i].push_back(prev_s + " " + word);
                    }
                }
            }
        }

        return possible_sentences[n];
    }
};


// valid[i]: means we could use some words in wordDict to form the first i char in s
