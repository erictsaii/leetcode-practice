class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> m;

        for (auto&c : word) m[c]++;

        int ans = INT_MAX;

        for (auto& mi : m) {
            int max_val = mi.second + k;
            int now = 0;
            for (auto& mj : m) {
                if (mj.second < mi.second) { // 因為已經假設mi是最小的freq
                    now += mj.second; 
                }
                else if (mj.second > max_val) {
                    now += mj.second - max_val;
                }
            }
            ans = min(ans, now);
        }

        return ans;
    }
};

// 4 2 1
