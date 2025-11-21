class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<vector<int>> index(26);
        for (int i = 0; i < s.size(); i++) {
            index[s[i]-'a'].push_back(i);
        }
        
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                int max_index = -1;
                auto it = upper_bound(index[i].begin(), index[i].end(), max_index);
                if (it == index[i].end()) break;
                max_index = *it;

                it = upper_bound(index[j].begin(), index[j].end(), max_index);
                if (it == index[j].end()) continue;
                max_index = *it;

                it = upper_bound(index[i].begin(), index[i].end(), max_index);
                if (it == index[i].end()) continue;
                ans++;
            }
        }
        return ans;
    }
};

// palindromes of length 3: OXO, OOO
// maximum combination of OXO: 26*25
// maximum combination of OXO: 26
// same subquence only count once
