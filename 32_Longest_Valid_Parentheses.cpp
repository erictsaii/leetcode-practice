class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk; // -1 for '(', -2 for ')'

        for (auto& c : s) {
            if (c == '(') {
                stk.push(-1);
            }
            else {
                if (stk.empty()) continue;
                int tmp = 0;

                if (stk.top() == -1) {
                    tmp = 2;
                    stk.pop();

                    while (!stk.empty() && stk.top() > 0) {
                        tmp += stk.top();
                        stk.pop();
                    }
                    stk.push(tmp);
                } 
                else if (stk.top() == -2) {
                    stk.push(-2);
                }
                else {
                    if (stk.size() >= 2) {
                        int num = stk.top();
                        stk.pop();
                        int t = stk.top();
                        stk.pop();
                        if (t == -1) {
                            tmp = num + 2;
                            while (!stk.empty() && stk.top() > 0) {
                                tmp += stk.top();
                                stk.pop();
                            }
                            stk.push(tmp);
                        }
                        else {
                            stk.push(t);
                            stk.push(num);
                            stk.push(-2);
                        }
                    }
                    else {
                        stk.push(-2);
                    }
                }
            }
        }

        int ans = 0;
        while (!stk.empty()) {
            ans = max(ans, stk.top());
            stk.pop();
        }
        return ans;
    }
};
