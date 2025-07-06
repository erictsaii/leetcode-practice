class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (auto& i : arr) {
            cnt[i]++;
        }
        int ans = -1;
        for (auto& c : cnt) {
            if (c.first == c.second && c.first > ans) {
                ans = c.first;
            }
        }
        return ans;
    }
};
