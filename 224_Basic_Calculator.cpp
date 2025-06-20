class Solution {
public:
    int calculate(string s) {
        stack<int> stk; // for the '(' and ')'
        int sum = 0;
        int i = 0;
        int sign = 1;

        for (i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                int tmp = 0;
                while (i<s.size() && isdigit(s[i])) {
                    tmp *= 10;
                    tmp += s[i] - '0';
                    i++;
                }
                i--;
                tmp *= sign;
                sum += tmp;
            }
            else if (s[i] == '(') {
                stk.push(sum);
                stk.push(sign); // sign of num in ()
                sum = 0;
                sign = 1;
            }
            else if (s[i] == ')') {
                sign = stk.top();
                stk.pop();
                int prev_sum = stk.top();
                stk.pop();
                sum = prev_sum + sign*sum;
            }
            else if (s[i] == '-') {
                sign = -1;
            }
            else if (s[i] == '+') {
                sign = 1;
            }
            else if (s[i] == ' ') {
                continue;
            }
        }

        return sum;
    }
};
