class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<vector<pair<int, int>>> max_three(n); // val, id

        int a, b;
        for (int i = 0; i < edges.size(); i++) {
            a = edges[i][0];
            b = edges[i][1];

            max_three[a].push_back({scores[b], b});
            sort(max_three[a].begin(), max_three[a].end(), greater<>());
            if (max_three[a].size() > 3) max_three[a].pop_back();

            max_three[b].push_back({scores[a], a});
            sort(max_three[b].begin(), max_three[b].end(), greater<>());
            if (max_three[b].size() > 3) max_three[b].pop_back();
        }

        int ans = -1;
        for (int i = 0; i < edges.size(); i++) {
            a = edges[i][0];
            b = edges[i][1];

            // a pick first
            int p1 = 0, p2 = 0;
            while (p1 < max_three[a].size() && max_three[a][p1].second == b) p1++;
            while (p1 < max_three[a].size() && p2 < max_three[b].size() && (max_three[b][p2].second == a || max_three[b][p2].second == max_three[a][p1].second)) p2++;
            if (p1 < max_three[a].size() && p2 < max_three[b].size()) ans = max(ans, max_three[a][p1].first + max_three[b][p2].first + scores[a] + scores[b]);

            // b pick first
            p1 = p2 = 0;
            while (p2 < max_three[b].size() && max_three[b][p2].second == a) p2++;
            while (p1 < max_three[a].size() && p2 < max_three[b].size() && (max_three[a][p1].second == b || max_three[a][p1].second == max_three[b][p2].second)) p1++;
            if (p1 < max_three[a].size() && p2 < max_three[b].size()) ans = max(ans, max_three[a][p1].first + max_three[b][p2].first + scores[a] + scores[b]);
        }
        return ans;
    }
};



// 4 nodes
// they should be a line:
// 1 -- 2 -- 3 -- 4

