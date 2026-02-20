class Solution {
public:
    int countBinarySubstrings(string s) {
        int curr = 1, prev = 0;
        int ans = 0;

        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i+1]) curr++;
            else {
                if (prev == 0) {
                    prev = curr;
                    curr = 1;
                    continue;
                }
                else {
                    ans += min(prev, curr);
                    prev = curr;
                    curr = 1; 
                }
            }
        }
        ans += min(prev, curr);

        return ans;
    }
};

// 2 2 2 2
