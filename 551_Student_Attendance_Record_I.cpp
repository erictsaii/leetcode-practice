class Solution {
public:
    bool checkRecord(string s) {
        int A_cnt = 0;
        int L_cnt = 0; 

        for (auto& c : s) {
            if (c == 'A') {
                A_cnt++;
                L_cnt = 0;
            }
            else if (c == 'L') L_cnt++;
            else L_cnt = 0;
            
            if (L_cnt >= 3) return false;
        }

        return A_cnt < 2;
    }
};
