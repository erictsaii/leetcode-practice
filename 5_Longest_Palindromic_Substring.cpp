class Solution {
public:
    string find_longest_palindrome(int l, int r, string s) {
        while (l>=0 && r<=s.size()-1) {
            if (s[l] != s[r]) break;
            l--;
            r++;
        }
        string result = "";

        for (int i = l+1; i <= r-1; i++) {
            result.push_back(s[i]);
        }

        return result;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for (int i = 0; i < n; i++) {
            string odd = find_longest_palindrome(i, i, s);
            string even = find_longest_palindrome(i, i+1, s);

            if (odd.size() > ans.size()) ans = odd;
            if (even.size() > ans.size()) ans = even;
        }
        return ans;
    }
};
