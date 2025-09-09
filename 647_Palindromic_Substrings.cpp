class Solution {
public:
    int count_palindrome(int left, int right, string& s) {
        int cnt = 0;
        while (left >= 0 && right < s.size()) {
            if (s[left] != s[right]) break;
            cnt++;
            left--;
            right++;
        }
        return cnt;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += count_palindrome(i, i, s) + count_palindrome(i, i+1, s);
        }
        return ans;
    }
};
