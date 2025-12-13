class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<int, vector<int>> m;

        int left, right;
        for (int i = 0; i < buildings.size(); i++) {
            left = buildings[i][0];
            right = buildings[i][1];
            m[left].push_back(i+1);
            m[right].push_back(-(i+1));
        }

        unordered_set<int> curr_buildings;
        priority_queue<pair<int, int>> pq; // height, id
        int x;
        int prev_height = -1;
        vector<vector<int>> ans;
        for (auto& i : m) {
            for (auto& id : i.second) {
                if (id > 0) {
                    curr_buildings.insert(id-1);
                    pq.push({buildings[id-1][2], id-1});
                }
                else {
                    curr_buildings.erase(abs(id)-1);
                }
            }

            while (pq.size() && !curr_buildings.count(pq.top().second)) {
                pq.pop();
            }
            
            int curr_height = pq.size() ? pq.top().first : 0;
            if (prev_height != curr_height) {
                ans.push_back({i.first, curr_height});
                prev_height = curr_height;
            }
        }
        return ans;
    }
};


// map<int, vector<int>> m;  // x-axis, a building enter or leave
// prefix -> set, indicate what buildings are in the current set
// priority_queue<pair<int, int>> pq; // height, id
