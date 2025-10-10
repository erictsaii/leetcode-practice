class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int suffix;
        int ans = INT_MIN;

        for (int i = n-1; i >= n-k; i--) {
            suffix = 0;
            for (int j = i; j >= 0; j -= k) {
                suffix += energy[j];
                ans = max(ans, suffix);
            }
        }  
        return ans;
    }
};

// suffix
