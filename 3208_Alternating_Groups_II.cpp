class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int n = colors.size();
            for (int i = 0; i < k-1; i++) {
                colors.push_back(colors[i]);
            }
            int cnt = 0, prev = -1, ans = 0;
            for (int i = 0; i < colors.size(); i++) {   
                if (colors[i] != prev) {
                    prev = colors[i];
                    if (cnt < k) cnt++;
                    if (cnt == k) ans++;
                }
                else {
                    prev = colors[i];
                    cnt = 1;
                }
            }
    
            return ans;
        }
    };