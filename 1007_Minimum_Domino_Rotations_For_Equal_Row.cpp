class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            int n = tops.size();
            vector<int> cnt(7, 0);
    
            // count the number of each number
            for (int i = 0; i < n; i++) {
                if (tops[i] == bottoms[i]) cnt[tops[i]]++;
                else {
                    cnt[tops[i]]++;
                    cnt[bottoms[i]]++;
                }
            }
    
            int max_element, max_times = -1;
            for (int i = 1; i <= 6; i++) {
                if(cnt[i] > max_times) {
                    max_element = i;
                    max_times = cnt[i];
                }
            }
            if (max_times < n) return -1;
    
            int to_top = 0, to_bottom = 0;
    
            for (int i = 0; i < n; i++) {
                if (tops[i] != max_element) to_top++;
                if (bottoms[i] != max_element) to_bottom++;
            }
    
            return min(to_top, to_bottom);
        }
    };