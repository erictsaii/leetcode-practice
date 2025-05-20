class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        for (auto& c : s) {
            if (c != ']') ans.push_back(c);
            else {
                // first, extract string
                string tmp = "";
                while (ans.back() != '[') {
                    tmp.push_back(ans.back());
                    ans.pop_back();
                }
                reverse(tmp.begin(), tmp.end());
                ans.pop_back(); // for '['

                // extract num
                string s_sum = "";
                while (ans.size() > 0 && isdigit(ans.back())) {
                    s_sum.push_back(ans.back());
                    ans.pop_back();
                } 
                reverse(s_sum.begin(), s_sum.end());

                // insert back
                int sum = stoi(s_sum);
                for (int i = 0; i < sum; i++) {
                    ans += tmp;
                }
            }
        }

        return ans;
    }
};