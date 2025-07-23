class Solution {
public:
    int helper(string &in, string& out, char to_find, int to_add) {
        int sum = 0;
        char c = (to_find == 'b') ? 'a' : 'b';

        for (int i = 0; i < in.size(); i++) {
            if (out.size() != 0 && in[i] == to_find && out.back() == c) {
                sum += to_add;
                out.pop_back();
            }
            else {
                out.push_back(in[i]);
            }
        }

        return sum;
    }
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        string tmp1, tmp2;
        if (x > y) {
            ans += helper(s, tmp1, 'b', x);
            ans += helper(tmp1, tmp2, 'a', y);
        }
        else {
            ans += helper(s, tmp1, 'a', y);
            ans += helper(tmp1, tmp2, 'b', x);
        }
        return ans;
    }
};


//  cdbcabab
