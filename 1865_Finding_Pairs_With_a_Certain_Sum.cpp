class FindSumPairs {
public:
    unordered_map<int, int> cnt1;
    unordered_map<int, int> cnt2;
    vector<int> _nums2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (auto& num : nums1) {
            cnt1[num]++;
        }
        for (auto& num : nums2) {
            cnt2[num]++;
        }
        _nums2 = nums2;
    }

    void add(int index, int val) {
        cnt2[_nums2[index]]--;
        _nums2[index] += val;
        cnt2[_nums2[index]]++;
    }

    int count(int tot) {
        int ans = 0;
        for (auto& i : cnt1) {
            ans += i.second * cnt2[tot-i.first];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
