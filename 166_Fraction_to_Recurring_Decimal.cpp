class Solution {
public:
    string fractionToDecimal(int n, int d) {
        if (n == 0) return "0"; 

        bool is_neg = (n < 0) ^ (d < 0);
        string ans = is_neg ? "-" : "";
        long numerator = abs((long)n);
        long denominator = abs((long)d);

        long integer = numerator / denominator;
        long remainder = numerator % denominator;

        ans.append(to_string(integer));
        if (remainder == 0) return ans;

        ans.push_back('.');

        unordered_map<int, int> m; // num, idx in ans
        while (remainder != 0) {
            remainder *= 10;
            integer = remainder / denominator;

            if (m.count(remainder)) {
                ans.insert(m[remainder], "(");
                ans.push_back(')');
                return ans;
            }

            ans.push_back(integer + '0');
            m[remainder] = ans.size()-1;
            remainder = remainder % denominator;
        }
        return ans;
    }
};

