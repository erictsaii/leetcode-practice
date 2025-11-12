class MyCalendar {
public:
    set<pair<int, int>> s;
    MyCalendar() {}
    
    bool book(int startTime, int endTime) {
        pair<int, int> e = {startTime, endTime};
        auto next_event = s.lower_bound(e);
        if (next_event != s.end() && endTime > next_event->first) return false;

        if (next_event != s.begin()) {
            auto prev_event = prev(next_event);
            if (prev_event->second > startTime) return false;
        }

        s.insert(e);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
