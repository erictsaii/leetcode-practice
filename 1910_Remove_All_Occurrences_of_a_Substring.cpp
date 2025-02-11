class Solution {
public:
    string removeOccurrences(string s, string part) {
        char last_char = part.back();
        deque<char> q;
        string ans = "";
        string tmp;

        for (int i = 0; i < s.size(); i++) {
            if ((s[i] == last_char) && (q.size() >= part.size()-1)) {
                tmp = s[i];
                for (int j = 0; j < part.size()-1; j++) {
                    tmp = q.back() + tmp;
                    q.pop_back();
                }

                if (tmp != part) {
                    for (int j = 0; j < tmp.size(); j++) {
                        q.push_back(tmp[j]);
                    }
                } 
            }
            else {
                q.push_back(s[i]);
            }
        } 

        while (q.size() != 0) {
            ans += q.front();
            q.pop_front();
        }

        return ans;
    }
};