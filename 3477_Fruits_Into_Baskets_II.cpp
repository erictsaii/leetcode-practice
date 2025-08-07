class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> visited(n, false);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int found = false;
            for (int j = 0; j < n && !found; j++) {
                if (fruits[i] <= baskets[j] && !visited[j]) {
                    visited[j] = true;
                    found = true;
                }
            }
            if (!found) ans++;
        }

        return ans;
    }
};
