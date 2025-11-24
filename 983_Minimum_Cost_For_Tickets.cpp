class Solution {
public:
    int memo[366]={0};

    int solve(vector<int>& days, vector<int>& costs, int pos) {
        if (pos >= days.size()) return 0;
        if (memo[pos] != 0) return memo[pos];
        int next_pos = pos;

        // 1-day pass
        while (next_pos < days.size() && days[next_pos] <= days[pos]) next_pos++;
        int one_day = costs[0] + solve(days, costs, next_pos);

        // 7-day pass
        while (next_pos < days.size() && days[next_pos] <= days[pos]+6) next_pos++;
        int seven_day = costs[1] + solve(days, costs, next_pos);

        // 30-day pass
        while (next_pos < days.size() && days[next_pos] <= days[pos]+29) next_pos++;
        int thirty_day = costs[2] + solve(days, costs, next_pos);

        return memo[pos] = min({one_day, seven_day, thirty_day});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return solve(days, costs, 0);
    }
};
