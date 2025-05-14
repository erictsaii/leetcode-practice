class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int _max = *max_element(candies.begin(), candies.end());
        int n = candies.size();

        vector<bool> ans(n, false);
        for (int i = 0; i < n; i++) {
            if (extraCandies + candies[i] >= _max) ans[i] = true;
        }

        return ans;
    }
};