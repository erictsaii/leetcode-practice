class Solution {
    public:
        vector<int> partitionLabels(string s) {
            vector<int> l(26, -1);
            vector<int> r(26, -1);
            for (int i = 0; i < s.size(); i++) r[s[i] - 'a'] = i;
            for (int i = s.size() - 1; i >= 0; i--) l[s[i] - 'a'] = i;
    
            vector<int> diff_array(s.size(), 0);
            for (int i = 0; i < 26; i++) {
                if (l[i] != -1) diff_array[l[i]]++;
                if (r[i] != -1) diff_array[r[i]]--;
            }
        
            vector<int> ans;
            int cnt = 0, sum = 0;
            for (int i = 0; i < s.size(); i++) {
                sum += diff_array[i];
                cnt++;
                if (sum == 0) {
                    ans.push_back(cnt);
                    cnt = 0;
                } 
            }
    
            return ans;
        }
    };
    
    // find the left most and right most of a 
    // difference array