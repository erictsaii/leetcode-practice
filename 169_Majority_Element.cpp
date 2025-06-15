class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority;
        int cnt = 0;

        for (auto& num : nums) {
            if (cnt == 0) majority = num;

            if (majority == num) cnt++;
            else cnt--;
        }
        
        return majority;
    }
};
