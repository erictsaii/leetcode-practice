class Solution {
public:
    void helper(int& sum, int to_append, int n, vector<int>& ans, bool& flag) {
        sum *= 10;
        sum += to_append;
        if (sum > n) {
            sum /= 10;
            flag = true;
            return;
        }
        ans.push_back(sum);
    }
    vector<int> lexicalOrder(int n) {
        int digit = 0, tmp = n;
        while (tmp != 0) {
            tmp /= 10;
            digit++;
        }
        vector<int> ans;

        int sum = 0;
        for (int a = 1; a<=9 && digit>=1; a++) {
            bool flag = false;
            helper(sum, a, n, ans, flag);
            if (flag) break;
            for (int b = 0; b<=9 && digit>=2; b++) {
                flag = false;
                helper(sum, b, n, ans, flag);
                if (flag) break;
                for (int c = 0; c<=9 && digit>=3; c++) {
                    flag = false;
                    helper(sum, c, n, ans, flag);
                    if (flag) break;
                    for (int d = 0; d<=9 && digit>=4; d++) {
                        flag = false;
                        helper(sum, d, n, ans, flag);
                        if (flag) break;
                        for (int e = 0; e<=9 && digit>=5; e++) {
                            flag = false;
                            helper(sum, e, n, ans, flag);
                            if (flag) break;  
                            sum /= 10;
                        }
                        sum /= 10;
                    }
                    sum /= 10;
                }
                sum /= 10;
            }
            sum /= 10;
        }

        return ans;
    }
};

// 50000
