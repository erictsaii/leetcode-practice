class MyCalendarThree {
public:
    map<int, int> m; // time, cnt

    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        m[startTime]++;
        m[endTime]--;

        int ans = 0;
        int prefix = 0;
        for (auto& i : m) {
            prefix += i.second;
            ans = max(ans, prefix);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
