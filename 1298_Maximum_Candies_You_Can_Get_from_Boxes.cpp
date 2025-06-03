class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        queue<int> can_open;

        vector<pair<bool, bool>> v(n, {false, false}); // get key, get box
        vector<bool> visited(n, false);
        for (int i = 0; i < initialBoxes.size(); i++) {
            v[initialBoxes[i]].second = true;
            if (status[initialBoxes[i]] == 1) {
                can_open.push(initialBoxes[i]);
                visited[initialBoxes[i]] = true;
            }
        }

        int ans = 0;

        while (!can_open.empty()) {
            int now_box = can_open.front();
            can_open.pop();

            ans += candies[now_box];

            for (auto& new_box : containedBoxes[now_box]) {
                v[new_box].second = true;
                if ((status[new_box] || v[new_box].first) && !visited[new_box]) {
                    visited[new_box] = true;
                    can_open.push(new_box);
                }
            }

            for (auto& k : keys[now_box]) {
                v[k].first = true;
                if (v[k].second && !visited[k]) {
                    visited[k] = true;
                    can_open.push(k);
                }
            }
        }

        return ans;
    }
};

// status: 1 means open, 0 means closed
// candies: num of candies in ith box
// keys: a list of key
// containedBoxes: list of the boxes 

// queue存可以開的box
// 有沒有會被重複開啟的box?
