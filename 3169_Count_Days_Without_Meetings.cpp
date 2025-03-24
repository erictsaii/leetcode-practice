class Solution {
    public:
        static bool cmp(const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        }
        int countDays(int days, vector<vector<int>>& meetings) {
            sort(meetings.begin(), meetings.end(), cmp);
            days -= meetings[0][1] - meetings[0][0] + 1;
            int prev = meetings[0][1];
    
            for (int i = 1; i < meetings.size(); i++) {
                if (prev >= meetings[i][1]) continue;
                if (prev >= meetings[i][0]) {
                    days -= meetings[i][1] - prev;
                    prev = meetings[i][1];
                }
                else {
                    days -= meetings[i][1] - meetings[i][0] + 1;
                    prev = meetings[i][1];
                }
            }
    
            return days;
        }
    };
    