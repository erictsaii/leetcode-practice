class RangeModule {
public:
    map<int, int> m;

    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto it = m.upper_bound(left);

        while (it != m.end() && it->first <= right) {
            right = max(right, it->second);
            it++;
            m.erase(prev(it));
        }

        if (it != m.begin() && left <= prev(it)->second) {
            it--;
            it->second = max(it->second, right);
        }
        else {
            m[left] = right;
        }
    }
    
    bool queryRange(int left, int right) {
        auto it = m.upper_bound(left);
        if (it == m.begin()) return false;
        return prev(it)->second >= right;
    }
    
    void removeRange(int left, int right) {
        auto it = m.lower_bound(left);
        int cut_end = -1;

        // for any interval that has first <= right, it should be erase (modify)
        while (it != m.end() && it->first <= right) {
            cut_end = max(cut_end, it->second);
            it++;
            m.erase(prev(it));
        }

        if (it != m.begin() && left < (--it)->second) {
            cut_end = max(cut_end, it->second);
            it->second = left;
        }

        if (right < cut_end) {
            m[right] = cut_end;
        }
    }
};


/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
