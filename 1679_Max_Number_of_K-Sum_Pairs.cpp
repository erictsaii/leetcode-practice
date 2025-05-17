class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map <int, int> m;
        int ans = 0;
        for (auto& n : nums) m[n]++;
        for (auto& n : nums) {
            if (m.find(n) != m.end() && m.find(k-n) != m.end() && ((n!=k-n) || (m[n] >= 2))) {
                m[n]--;
                m[k-n]--;
                if (m[n] == 0) m.erase(n);
                if (m[k-n] == 0) m.erase(k-n);
                ans++;
            }
        }
        return ans;
    }
};

// one operation: pick 2 numbers (sum equal to k) and delete them
// return max operations I could perform 