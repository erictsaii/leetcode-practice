class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int max_val = -1;
        for (int i = 0; i < num.size()-2; i++) {
            if (num[i]==num[i+1] && num[i+1]==num[i+2]) {
                if (num[i]-'0' > max_val) {
                    max_val = num[i]-'0';
                    ans = num.substr(i, 3);
                }    
            }
        }

        return ans;
    }
};
