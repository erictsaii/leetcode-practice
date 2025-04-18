class Solution {
    public:
        vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
            vector<int> ans(spells.size());
            sort(potions.begin(), potions.end());
    
            for (int i = 0; i < spells.size(); i++) {
                int l = 0, r = potions.size()-1;
                int pos = potions.size();
                while (l <= r) {
                    int mid = (l+r) / 2;
                    if (1LL * potions[mid] * spells[i] >= success) {
                        r = mid - 1;
                        pos = mid;
                    }
                    else {
                        l = mid + 1;
                    }
                }
                ans[i] = potions.size() - pos;
            }
    
    
           return ans; 
        }
    };