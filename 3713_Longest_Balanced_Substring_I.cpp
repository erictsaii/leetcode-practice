class Solution {
public:
    bool same_cnt(vector<int> & freq) {
        int prev = -1;

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;
            if (prev == -1) {
                prev = freq[i];
            }
            else if (prev != freq[i]) {
                return false;
            }
        }
        return true;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j]-'a']++;

                if (same_cnt(freq)) ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};
