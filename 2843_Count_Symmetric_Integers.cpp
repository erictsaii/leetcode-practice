class Solution {
    public:
        bool is_symmetric(int num) {
            string s = to_string(num);
            if (s.size() % 2) return false;
            int sum = 0;
            for (int i = 0; i < s.size() / 2; i++) {
                sum += s[i] - '0';
            }
            for (int i = s.size() / 2; i < s.size(); i++) {
                sum -= s[i]- '0';
            }
            return (sum == 0);
        }
        int countSymmetricIntegers(int low, int high) {
            int ans = 0;
            for (int i = low; i <= high; i++) {
                if (is_symmetric(i)) ans++;
            }
    
            return ans;
        }
    };