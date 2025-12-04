class Solution {
public: 
    vector<int> tree; // 1-indexed

    void update(int index, int delta) {
        while (index < tree.size()) {
            tree[index] += delta;
            index += index & -index;
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int offset = n + 1;
        tree.assign(2 * (n + 1), 0);

        update(offset, 1); // for initial prefix=0

        int curr_prefix = 0;
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) curr_prefix++;
            else curr_prefix--;

            ans += query(offset + curr_prefix - 1);

            update(offset + curr_prefix, 1);
        }
        return ans;
    }
};

// 0 1 0 1
