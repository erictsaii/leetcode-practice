class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<set<int>> col(n+1), row(n+1);

        for (auto& building : buildings) {
            col[building[0]].insert(building[1]);
            row[building[1]].insert(building[0]);
        }

        int ans = 0;
        for (auto& building : buildings) {
            auto c = col[building[0]].lower_bound(building[1]);
            auto r = row[building[1]].lower_bound(building[0]);
            if (c != col[building[0]].begin() && (++c) != col[building[0]].end() && r != row[building[1]].begin() && (++r) != row[building[1]].end()) {
                ans++;
            }
        }
        return ans;
    }
};

// A building is covered if there is at least one building in all four directions
// a set for each row, for each col
