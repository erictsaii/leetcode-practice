class Solution {
public:
    int get_minutes(string s) {
        int h = (s[0]-'0')*10 + s[1]-'0';
        int m = (s[3]-'0')*10 + s[4]-'0';
        
        return h*60 + m;
    }

    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());

        int ans = INT_MAX;
        for (int i = 0; i < timePoints.size()-1; i++) {
            ans = min(ans, get_minutes(timePoints[i+1]) - get_minutes(timePoints[i]));
        }

        // deal with cross 24 hours
        ans = min(ans, get_minutes(timePoints[0]) + 24*60 - get_minutes(timePoints.back()));

        return ans;
    }
};
