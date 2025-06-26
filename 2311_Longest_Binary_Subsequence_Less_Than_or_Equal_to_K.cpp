class Solution {
public:
    int longestSubsequence(string s, int k) {
        int zero_cnt = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') zero_cnt++;
        }

        long sum = 0;
        long pow = 1;
        int one_cnt = 0;
        for (int i = s.size()-1; i >= 0 && sum <= k && pow <= k; i--) {
            if (s[i] == '1') {
                sum += pow;
                one_cnt++;
            }
            pow *= 2;
        }

        if (sum > k) one_cnt--;

        return zero_cnt + one_cnt;
    }
};

// 0可以全選
// 選完之後慢慢填1
