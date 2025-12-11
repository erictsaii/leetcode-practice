class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> m; // end with value x, len

        int ans = 1;
        for (int i = 0; i < arr.size(); i++) {
            int prev_val = arr[i] - difference;
            if (m.count(prev_val)) {
                m[arr[i]] = m[prev_val] + 1;
                ans = max(ans, m[arr[i]]);
            }
            else {
                m[arr[i]] = 1;
            }
        }
        return ans;
    }
};
