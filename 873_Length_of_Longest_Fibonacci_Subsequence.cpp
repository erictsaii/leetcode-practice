class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            unordered_map<int, bool> m;
            for (auto & a : arr) {
                m[a] = true;
            }
            int x, y, tmp, ans = 0, n;
            for (int i = 0; i < arr.size(); i++) {
                for (int j = i + 1; j < arr.size(); j++) {
                    x = arr[i];
                    y = arr[j];
                    n = 2;
                    
                    while (m.find(x + y) != m.end()) {
                        tmp = x + y;
                        x = y;
                        y = tmp;
                        n++;
                    }
    
                    if (n >= 3) ans = max(ans, n);
                }
            }
    
            return ans;
        }
    };