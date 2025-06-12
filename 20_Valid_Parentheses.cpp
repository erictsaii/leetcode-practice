class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_set<char> left;
        unordered_map<char, char> mapping;
        left.insert('(');
        left.insert('{');
        left.insert('[');
        mapping['('] = ')';
        mapping['{'] = '}';
        mapping['['] = ']';

        for (auto& c : s) {
            if (left.count(c)) stk.push(c);
            else {
                if (stk.empty()) return false;
                if (mapping[stk.top()] == c) stk.pop();
                else return false;
            }
        }

        return stk.empty();
    }
};
