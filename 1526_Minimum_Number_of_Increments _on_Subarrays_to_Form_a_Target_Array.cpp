class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = target[0];
        int prev = target[0];

        for (int i = 1; i < target.size(); i++) {
            if (prev < target[i]) {
                ans += target[i] - prev;
            }
            prev = target[i];
        }

        return ans;      
    }
};
