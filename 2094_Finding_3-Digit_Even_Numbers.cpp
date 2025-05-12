class Solution {
public:
    void permute(vector<int>& ans, vector<int>& cnt, int len, int sum) {
        if (len == 3) {
            if ((sum&1) == 0) ans.push_back(sum);
        }
        else {
            for (int i = 0; i < cnt.size(); i++) {
                if (cnt[i] == 0) continue;
                if (i==0 && len==0) continue;
                cnt[i]--;
                permute(ans, cnt, len+1, sum*10 + i);
                cnt[i]++;
            }
        }
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> cnt(10, 0);
        for (int i = 0; i < digits.size(); i++) {
            if (cnt[digits[i]] < 3) cnt[digits[i]]++;
        }
        vector<int> ans;
        permute(ans, cnt, 0, 0);

        sort(ans.begin(), ans.end());
        return ans;
    }
};

