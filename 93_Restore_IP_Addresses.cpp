class Solution {
public:
    vector<string> ans;

    void solve(string& s, int pos, string curr_string, int dots) {
        if (pos == s.size()) {
            if (dots == 4) {
                curr_string.pop_back();
                ans.push_back(curr_string);
            }
            return;
        }

        if (dots == 4) return;

        if (s[pos] == '0') {
            solve(s, pos+1, curr_string + "0.", dots+1);
            return;
        }

        string tmp = "";
        for (; pos < s.size(); pos++) {
            tmp.push_back(s[pos]);
            if (stoi(tmp) > 255) break;
            solve(s, pos+1, curr_string + tmp + ".", dots+1);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        solve(s, 0, "", 0);
        return ans;
    }
};
