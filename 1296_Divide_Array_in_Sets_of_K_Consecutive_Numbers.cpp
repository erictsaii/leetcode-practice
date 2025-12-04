class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto& n : nums) freq[n]++;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (freq[nums[i]] == 0) continue;
            for (int j = 0; j < k; j++) {
                freq[nums[i]+j]--;
                if (freq[nums[i]+j] < 0) return false;
            }
        }
        return true;
    }
};


// calculate the frequency of each number
// sort the number, start from the smallest number
// for every number, we substract the next k number's frequency by 1
// if we can't, return false
