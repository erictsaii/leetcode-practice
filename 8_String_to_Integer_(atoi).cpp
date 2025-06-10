class Solution {
public:
    int myAtoi(string s) {
        long sum = 0;
        int max_val = INT_MAX, min_val = INT_MIN;
        int idx = 0;
        int sign = 1; // 1 for positive

        while (s[idx] == ' ') idx++;

        if (s[idx] == '+') idx++;
        else if (s[idx] == '-') {
            idx++;
            sign = 0;
        }

        while (isdigit(s[idx])) {
            sum *= 10;
            sum += s[idx] - '0';
            idx++;
            if (sign && sum >= INT_MAX) return INT_MAX;
            else if (!sign && -sum <= INT_MIN) return INT_MIN;
        } 

        return (sign) ? sum : -sum;
    }
};

// 1. ignore any leading " "
// 2. check if the first char is '+' or '-', if neither, then it's positive
// 3. skip leading zeros, read until end or non-digit char
// 4. rounding the result to [-2^31, 2^31-1], might use long
