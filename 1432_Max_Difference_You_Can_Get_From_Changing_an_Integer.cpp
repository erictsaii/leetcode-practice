class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string max_val = s, min_val = s;

        char to_be_nine = '9';
        char to_be_one_or_zero = '0';

        // find the first digit not '9'
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '9') {
                to_be_nine = s[i];
                break;
            }
        }

        // transform that digit into '9'
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == to_be_nine) {
                max_val[i] = '9';
            }
        }

        // try to get min_val
        if (s[0] != '1') {
            to_be_one_or_zero = s[0];
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == to_be_one_or_zero) {
                    min_val[i] = '1';
                }
            }
        }
        else {
            for (int i = 1; i < s.size(); i++) {
                if (s[i] != '0' && s[i] != '1') {
                    to_be_one_or_zero = s[i];
                    break;
                }
            }
            for (int i = 1; i < s.size(); i++) {
                if (s[i] == to_be_one_or_zero) {
                    min_val[i] = '0';
                }
            }
        }

        return stoi(max_val) - stoi(min_val);
    }
};
