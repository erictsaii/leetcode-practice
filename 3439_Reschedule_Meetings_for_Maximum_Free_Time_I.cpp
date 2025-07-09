class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        vector<int> freetime;
        freetime.push_back(startTime[0]);
        for (int i = 0; i < n - 1; i++) {
            freetime.push_back(startTime[i+1] - endTime[i]);
        }
        freetime.push_back(eventTime - endTime[n-1]);

        int ans = 0;
        int sum = 0;
        int start = 0;
        for (int i = 0; i < freetime.size(); i++) {
            if (i - start > k) {
                sum -= freetime[start];
                start++;
            }
            sum += freetime[i];
            ans = max(ans, sum);
        }

        return ans;
    }
};
