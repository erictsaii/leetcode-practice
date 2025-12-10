class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            }
            else if (s[i] == ')') {
                if (stk.size()) {
                    s[i] = ']';
                    s[stk.top()] = '[';
                    stk.pop();
                }
            }
        }
        
        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i])) ans.push_back(s[i]);
            else if (s[i] == '[') ans.push_back('(');
            else if (s[i] == ']') ans.push_back(')');
        }
        return ans;
    }
};

// we could have a stack to memorize the index of '('
// whenever we meet a ')', pop one index of '(' from the stack, and mark them to be valid 
