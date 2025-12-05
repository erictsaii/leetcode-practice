class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            string s = to_string(num);
            int sum = 0;

            for (auto& c : s) sum += c-'0';
            num = sum; 
        }
        return num;
    }
};

