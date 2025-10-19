class Solution {
public:
    string ans;
    unordered_set<string> memo;

    void solve(string s, int a, int b) {
        if (memo.count(s)) return;
        memo.insert(s);

        string add = s;
        string rotate;

        for (int i = 1; i < s.size(); i += 2) {
            add[i] = (((add[i]-'0') + a) % 10) + '0';
        }

        rotate = s.substr(s.size()-b, b);
        rotate.append(s.substr(0, s.size()-b));

        solve(add, a, b);
        solve(rotate, a, b);
        
        if (ans > add) ans = add;
        if (ans > rotate) ans = rotate;
    }

    string findLexSmallestString(string s, int a, int b) {
        ans = string(100,'9');
        solve(s, a, b);
        return ans;
    }
};

