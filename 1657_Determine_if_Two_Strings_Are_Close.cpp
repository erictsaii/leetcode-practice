class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        int n = word1.size();

        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);

        for (int i = 0; i < n; i++) {
            cnt1[word1[i] - 'a']++;
            cnt2[word2[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (!cnt1[i] && cnt2[i] || cnt1[i] && !cnt2[i]) return false; 
        }

        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());

        for (int i = 0; i < 26; i++) {
            if (cnt1[i] != cnt2[i]) return false;
        }

        return true;
    }
};

// op1: 把字串中的char swap
// op2: 把字全互換: aacabb -> bbcbaa

// return close or not
// 可以先sort
// len不同return false

// aabbbc
// abbccc