class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;   
        m['X'] = 10;   
        m['L'] = 50;   
        m['C'] = 100;   
        m['D'] = 500;   
        m['M'] = 1000;   

        int idx = s.size()-1;
        int ans = 0;

        while (idx >= 0) {
            if (idx-1 >= 0 && m[s[idx-1]] < m[s[idx]]) {
                ans += -m[s[idx-1]] + m[s[idx]];
                idx-=2;
            } 
            else {
                ans += m[s[idx]];
                idx--;
            }
        }
        return ans;
    }
};
