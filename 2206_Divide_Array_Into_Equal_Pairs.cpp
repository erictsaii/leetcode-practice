class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            unordered_map<int, int> m;
    
            for (int i = 0; i < nums.size(); i++) {
                m[nums[i]]++;
            }
    
            for (auto mi : m) {
                if (mi.second & 1) return false;
            }
            return true;
        }
    };