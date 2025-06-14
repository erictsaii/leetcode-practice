class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);

        char to_nine = '9';
        char to_zero = '0';

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '9') {
                to_nine = s[i];
                break;
            }
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                to_zero =  s[i];
                break;
            }
        }

        string max_s = s, min_s = s;

        for (int i = 0; i < max_s.size(); i++) {
            if (max_s[i] == to_nine) {
                max_s[i] = '9';
            }
            if (min_s[i] == to_zero) {
                min_s[i] = '0';
            }
        } 


        return stoi(max_s) - stoi(min_s);
    }
};
