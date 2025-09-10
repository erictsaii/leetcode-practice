class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> need_teach;

        // find all person that need additional teaching
        for (auto& friendship : friendships) {
            int u = friendship[0], v = friendship[1];
            unordered_set<int> have;

            for (int i = 0; i < languages[u-1].size(); i++) {
                have.insert(languages[u-1][i]);
            }

            bool flag = false;
            for (int i = 0; i < languages[v-1].size(); i++) {
                if (have.count(languages[v-1][i])) flag = true;
            }
            if (!flag) {
                need_teach.insert(u);
                need_teach.insert(v);
            }
        }

        vector<int> cnt(n+1, 0);
        int max_cnt = 0;
        for (auto& person : need_teach) {
            for (int i = 0; i < languages[person-1].size(); i++) {
                cnt[languages[person-1][i]]++;
                max_cnt = max(max_cnt, cnt[languages[person-1][i]]);
            }
        }
        return need_teach.size() - max_cnt;
    }
};
