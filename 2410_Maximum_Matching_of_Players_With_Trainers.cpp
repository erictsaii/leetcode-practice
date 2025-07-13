class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int ans = 0;
        int t = 0;

        for (int i = 0; i < players.size(); i++) {
            while (t < trainers.size() && players[i] > trainers[t]) {
                t++;
            }
            if (t < trainers.size()) {
                t++;
                ans++;
            }
        }

        return ans;
    }
};
