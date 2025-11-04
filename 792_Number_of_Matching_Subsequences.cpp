class Solution {
public:
    bool check(string& word, vector<vector<int>>& v) {
        int max_index = -1;
        for (auto& c : word) {
            auto it = upper_bound(v[c-'a'].begin(), v[c-'a'].end(), max_index);
            if (it == v[c-'a'].end()) return false;
            max_index = *it;
        }
        return true;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> v(26);
        for (int i = 0; i < s.size(); i++) {
            v[s[i]-'a'].push_back(i);
        }

        int ans = 0;
        for (auto& word : words) {
            if (check(word, v)) ans++;
        }
        return ans;
    }
};

// first, build a map to record every letter's index in s
// e.g. abc -> a: 0, b: 1, c: 2

// for every word, we need to check 
// whether we can form the word using s in the acsending order of s's index
