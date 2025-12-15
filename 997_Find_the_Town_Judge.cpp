class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1, 0);
        vector<int> outdegree(n+1, 0);

        for (auto& t : trust) {
            outdegree[t[0]]++;
            indegree[t[1]]++;
        }

        int town_judge = -1;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == n-1 && outdegree[i] == 0) {
                if (town_judge != -1) return -1;
                town_judge = i;
            }
        }
        return town_judge;
    }
};
