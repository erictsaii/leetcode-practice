class Solution {
public:
    int maxOperations(string s) {
        int ans = 0;
        int group_cnt = 0;
        int prefix = 0;

        for (auto& c : s) {
            if (c == '1') {
                group_cnt++;
            }    
            else { // '0'
                if (group_cnt) {
                    prefix += group_cnt;
                    ans += prefix;
                    group_cnt = 0;
                }
            }
        }
        return ans;
    }
};


// find "10"
// move '1' to the right, next to another '1' or end of the string

// 以0隔開，數1的數量，prefix sum 
