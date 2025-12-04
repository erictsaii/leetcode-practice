class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, need;

        for (auto& num : nums) freq[num]++;

        for (auto& num : nums) {
            if (freq[num] == 0) continue;
            // for every element, it has two choices
            // 1. join the existing seq
            if (need[num]) {
                freq[num]--;
                need[num]--;
                need[num+1]++;
                continue;
            }

            // 2. start its own seq
            if (freq[num+1] && freq[num+2]) {
                freq[num]--;
                freq[num+1]--;
                freq[num+2]--;
                need[num+3]++;
                continue;
            }
            return false;
        }
        return true;
    }
};



// 1: 1
// 2: 1
// 3: 2
// 4: 2
// 5: 2
