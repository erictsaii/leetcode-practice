class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime,
                    vector<int>& endTime) {
        vector<int> gaps(1, startTime[0]);
        for (int i = 1; i < startTime.size(); i++) {
            gaps.push_back(startTime[i] - endTime[i - 1]);
        }
        gaps.push_back(eventTime - endTime.back());

        vector<int> largestRight(gaps.size(), 0);
        for (int i = gaps.size() - 2; i >= 0; i--) {
            largestRight[i] = max(largestRight[i + 1], gaps[i + 1]);
        }

        vector<int> largestLeft(gaps.size(), 0);
        for (int i = 2; i < gaps.size(); i++) {
            largestLeft[i] = max(largestLeft[i - 1], gaps[i - 2]);
        }

        int maxi = 0;
        for (int i = 1; i < gaps.size(); i++) {
            int meetingSize = endTime[i - 1] - startTime[i - 1];
            if (meetingSize <= max(largestLeft[i], largestRight[i])) {
                maxi = max(maxi, meetingSize + gaps[i] + gaps[i - 1]);
            }
            else maxi = max(maxi, gaps[i] + gaps[i - 1]);
        }
        return maxi;
    }
};
