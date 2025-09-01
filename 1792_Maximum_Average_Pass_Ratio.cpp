class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq; // profit, idx

        for (int i = 0; i < classes.size(); i++) {
            int p = classes[i][0], t = classes[i][1];
            double profit = (double)(p+1) / (t+1) - (double)p / t;
            pq.push({profit, i});
        }

        while (extraStudents--) {
            int idx = pq.top().second;
            pq.pop();
            classes[idx][0]++;
            classes[idx][1]++;
            int p = classes[idx][0], t = classes[idx][1];
            double profit = (double)(p+1) / (t+1) - (double)p / t;
            pq.push({profit, idx});
        }

        double ans = 0.0;
        for (int i = 0; i < classes.size(); i++) {
            ans += (double)classes[i][0] / classes[i][1];
        }
        ans /= (double)classes.size();

        return ans;
    }
};
