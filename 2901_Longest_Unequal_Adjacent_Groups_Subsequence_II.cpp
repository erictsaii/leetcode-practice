class Solution {
public:
    bool hamdis_is_1(string a, string b) {
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) cnt++;
        }
        return cnt == 1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);

        int _max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[i] != groups[j] && words[i].size() == words[j].size() && hamdis_is_1(words[i], words[j]) && dp[i] < dp[j]+1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            _max = max(dp[i], _max);
        }

        int start_idx = -1;
        for (int i = 0; i < n; i++) {
            if (dp[i] == _max) {
                start_idx = i;
                break;
            }
        }
        vector<string> ans;
        ans.push_back(words[start_idx]);
        for (int i = parent[start_idx]; i != -1; i = parent[i]) {
            ans.push_back(words[i]);
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// 要找到一個subsequence，要滿足: 
// 1. 相鄰indice的group不相同
// 2. 相鄰word"長度相同"，且ham dis是1

// dp?
// 1維: dp[i] = max( dp[i-1]+1 or dp[i-2]+1 ...) 


