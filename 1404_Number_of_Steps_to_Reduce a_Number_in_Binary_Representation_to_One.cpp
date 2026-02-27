class Solution {
public:
    void add_one(string& s) {
        string new_s;
        int carry = 1;
        
        for (int i = s.size() - 1; i >= 0; i--) {
            int sum = carry + s[i] - '0';

            if (sum >= 2) {
                carry = 1;
                new_s.push_back(sum - 2 + '0');
            }
            else {
                carry = 0;
                new_s.push_back(sum + '0');
            }
        }

        if (carry) new_s.push_back('1');
        reverse(new_s.begin(), new_s.end());

        s = new_s;
    }

    int numSteps(string s) {
        int ans = 0;

        while (s != "1") {
            ans++;
            if (s.back() == '0') {
                s.pop_back();
            }
            else {
                add_one(s);
            }
        }

        return ans;        
    }
};
