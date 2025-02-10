class Solution {
    public:
        string clearDigits(string s) {
            deque<char> dq;
            string ans = "";
    
            for (auto c : s) {
                if (isalpha(c)) {
                    dq.push_back(c);
                }
                else {
                    if (dq.size() != 0 && isalpha(dq.back())) {
                        dq.pop_back();
                    }
                    else {
                        dq.push_back(c);
                    }
                }
            }
    
            while(dq.size() != 0) {
                ans += dq.front();
                dq.pop_front();
            }
    
            return ans;
        }
    };