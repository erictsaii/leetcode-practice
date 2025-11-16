class Solution {
public:
    static bool cmp(const string& a, const string& b) {
        return a.size() < b.size();
    }

    bool is_predecessor(const string& a, const string& b) {
        // check if a is predecessor of b
        if (b.size() - a.size() != 1) return false;
        
        bool remain = true;
        for (int i = 0, j = 0; i < a.size() && j < b.size(); i++, j++) {
            if (a[i] != b[j]) {
                if (!remain) return false;
                remain = false;
                i--;
            }
        }
        return true;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);

        sort(words.begin(), words.end(), cmp);
        
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (is_predecessor(words[i], words[j])) {
                    dp[j] = max(dp[j], dp[i]+1);
                    ans = max(ans, dp[j]);
                }
            }
        }
        return ans;
    }
};

// O(n^2)

