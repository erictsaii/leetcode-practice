class Solution {
public:
    vector<string> ans;

    void backtrack(int pos, string& digits, unordered_map<char, vector<string>>& m, string s) {
        if (pos == digits.size()) {
            ans.push_back(s);
        }
        else {
            auto mapping = m[digits[pos]];
            for (auto c : mapping) {
                backtrack(pos+1, digits, m, s + c);
            }
        }

    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        unordered_map<char, vector<string>> m;
        m['2'] = {"a", "b", "c"};
        m['3'] = {"d", "e", "f"};
        m['4'] = {"g", "h", "i"};
        m['5'] = {"j", "k", "l"};
        m['6'] = {"m", "n", "o"};
        m['7'] = {"p", "q", "r", "s"};
        m['8'] = {"t", "u", "v"};
        m['9'] = {"w", "x", "y", "z"};

        backtrack(0, digits, m, "");

        return ans;
    }
};
