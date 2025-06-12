class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int a, b;

        for (auto& token : tokens) {
            if (token.size() >= 2) {
                stk.push(stoi(token));
            }
            else {
                if (isdigit(token[0])) {
                    stk.push(token[0] - '0');
                }
                else {
                    b = stk.top(), stk.pop();
                    a = stk.top(), stk.pop();
                    if (token[0] == '+') stk.push(a + b);
                    else if (token[0] == '-') stk.push(a - b);
                    else if (token[0] == '*') stk.push(a * b);
                    else stk.push(a / b);
                }
            }
        }

        return stk.top();
    }
};
