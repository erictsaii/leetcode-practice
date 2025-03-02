class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            map <int, int> m;
            vector<vector<int>> ans;
            for (auto &i : nums1) {
                m[i[0]] = m[i[0]] + i[1];
            }
            for (auto &i : nums2) {
                m[i[0]] = m[i[0]] + i[1];
            }
            for (auto x : m) {
                ans.push_back({x.first, x.second});
            }
    
            return ans;
        }
    };