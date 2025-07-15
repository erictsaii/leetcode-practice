class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int sign = 1;
        int i;

        int n = s.size();
        for (i = 0; i < n; i++) {
            if (s[i] == ' ') continue;
            if (isdigit(s[i])) {
                int sum = 0;
                while (isdigit(s[i])) {
                    sum *= 10;
                    sum += s[i] - '0';
                    i++;
                }
                i--;
                stk.push(sign * sum);
            }
            else if (s[i] == '+') {
                sign = 1;
            }
            else if (s[i] == '-') {
                sign = -1;
            }
            else if (s[i] == '*' || s[i] == '/') {
                int is_mul = 1;
                if (s[i] == '/') is_mul = 0;
                i++;
                while (s[i] == ' ') {
                    i++;
                }
                int num2 = 0;
                while (isdigit(s[i])) {
                    num2 *= 10;
                    num2 += s[i] - '0';
                    i++;
                }
                i--;
                int num1 = stk.top();
                stk.pop();
                if (is_mul) stk.push(num1 * num2);
                else stk.push(num1 / num2);
            }
        }

        int ans = 0;
        while (stk.size()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};
