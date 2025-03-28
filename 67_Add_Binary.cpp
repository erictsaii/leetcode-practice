class Solution {
    public:
        string addBinary(string a, string b) {
            if (a.size() < b.size()){
                swap(a, b);
            }
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
    
            int carry = 0;
            string ans = "";
            for (int i = 0; i < b.size(); i++) {
                int sum = a[i] + b[i] - '0' - '0' + carry;
                if (sum >= 2) {
                    carry = 1;
                    sum -= 2;
                }
                else {
                    carry = 0;
                }
    
                char to_push = (sum == 1) ? '1' : '0';
                ans.push_back(to_push);
            }
    
            for (int i = b.size(); i < a.size(); i++) {
                int sum = a[i] - '0' + carry;
                if (sum >= 2) {
                    carry = 1;
                    sum -= 2;
                }
                else {
                    carry = 0;
                }
    
                char to_push = (sum == 1) ? '1' : '0';
                ans.push_back(to_push);
            }
    
            if (carry == 1) ans.push_back('1');
    
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };