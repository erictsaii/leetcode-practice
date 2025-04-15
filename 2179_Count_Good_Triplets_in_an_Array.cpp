class Solution {
    public:
        vector<long long> tree;
    
        void update(int idx, int val) { // val is difference between new val and old val
            idx++;
            while (idx < tree.size()) {
                tree[idx] += val;
                idx += idx & -idx;
            }
        }
    
        long long query(int idx) {
            idx++;
            long long result = 0;
            while (idx > 0) {
                result += tree[idx];
                idx -= idx & -idx;
            }
            return result;
        }
    
        long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
            int n = nums1.size();
            long long ans = 0;
            vector<int> m(n, 0);
            for (int i = 0; i < n; i++) m[nums1[i]] = i;
    
            tree.resize(n+1, 0);
    
            for (int i : nums2) {
                int nums1_idx = m[i];
                long long left = query(nums1_idx);
                long long all = query(n-1);
                long long right = (n-1-nums1_idx) - (all-left);
                ans += left * right;
                update(nums1_idx, 1);
            }
    
            return ans;
        }
    };