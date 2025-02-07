class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball_map;
        unordered_map<int, int> color_map;
        vector<int> ans;
        int x, y, prev;
        for (auto &q: queries) {
            x = q[0];
            y = q[1];
            if (ball_map.count(x) != 0) {
                prev = ball_map[x];
                color_map[prev]--;
                if (color_map[prev] == 0) color_map.erase(prev);
            }
            ball_map[x] = y;
            color_map[y]++;
            ans.push_back(color_map.size());
        }

        return ans;
    }
};

