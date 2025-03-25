class Solution {
    public:
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            map<int, int> m; // idx, how many ropes
            int cnt = 0;
            for (auto& rectangle : rectangles) {
                int start = rectangle[1];
                int end = rectangle[3];
                m[start+1]++;
                m[end]--; 
            }
            int sum = 0;
            for (auto& mi : m) {
                sum += mi.second;
                if (sum == 0) cnt++;
            }
            if (cnt >= 3) return true;
    
            m.clear();
            cnt = 0;
            for (auto& rectangle : rectangles) {
                int start = rectangle[0];
                int end = rectangle[2];
                m[start+1]++;
                m[end]--; 
            }
            sum = 0;
            for (auto& mi : m) {
                sum += mi.second;
                if (sum == 0) cnt++;
            }
            if (cnt >= 3) return true;
    
            return false;
        }
    };
    