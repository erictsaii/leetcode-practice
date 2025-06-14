class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> m; // val, timestamp
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        string rtn = "";
        int l = 0, r = m[key].size()-1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (m[key][mid].second <= timestamp) {
                rtn = m[key][mid].first;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return rtn;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
