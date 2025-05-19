class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> m1;
        unordered_map<int, bool> m2;

        for (auto& n : nums1) m1[n] = true;
        for (auto& n : nums2) m2[n] = true;

        vector<vector<int>> ans(2);
        for (auto& i : m1) {
            if (m2.find(i.first) == m2.end()) ans[0].push_back(i.first);
        }
        for (auto& i : m2) {
            if (m1.find(i.first) == m1.end()) ans[1].push_back(i.first);
        }
        return ans;
    }
};