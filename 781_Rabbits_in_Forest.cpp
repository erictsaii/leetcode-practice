class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            int ans = 0;
            unordered_map<int, int> cnt;
    
            for (int i = 0; i < answers.size(); i++) {
                cnt[answers[i]]++;
            }
    
            for (auto i : cnt) {
                ans += ceil((double)i.second / (i.first + 1)) * (i.first + 1);
            }
    
            return ans;
        }
    };
    
    // 如果回答的數量相同，可能顏色就相同
    