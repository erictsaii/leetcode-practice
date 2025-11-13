class Solution {
public:
    int get_cost(string& digits, int startAt, int moveCost, int pushCost) {
        int total = 0;
        int i = 0;
        while (digits[i] == '0') i++;

        for (; i < digits.size(); i++) {
            if (digits[i]-'0' != startAt) {
                total += moveCost;
                startAt = digits[i]-'0';
            }
            total += pushCost;
        }
        return total;
    }

    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        // choice 1
        int m = targetSeconds / 60, s = targetSeconds % 60;
        string digits = to_string(m*100 + s);

        int ans = (m != 100) ? get_cost(digits, startAt, moveCost, pushCost) : INT_MAX;
        if (m == 0 || s+60 > 99) return ans;

        // choice 2
        m--;
        s += 60;
        digits = to_string(m*100 + s);
        ans = min(ans, get_cost(digits, startAt, moveCost, pushCost));
        return ans;
    }
};

// 一開始手會在某個數字上
// 移動一次需要moveCost
// 按一次需要pushCost

// given targetSeconds, minimize the total cost

// how to convert targetSeconds to digit?
// 600 s: 1000 960 
// 76 s: 116 76
// every targetSeconds have only two choices
