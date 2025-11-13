class SnapshotArray {
public:
    vector<vector<int>> arr; // snap_id
    vector<unordered_map<int, int>> m; // snap_id to value
    int snap_cnt;

    SnapshotArray(int length) {
        arr.assign(length, {});
        m.assign(length, {});
        snap_cnt = 0;
    }
    
    void set(int index, int val) {
        if (arr[index].empty() || arr[index].back() != snap_cnt) arr[index].push_back(snap_cnt);
        m[index][snap_cnt] = val;
    }
    
    int snap() {
       snap_cnt++; 
       return snap_cnt-1;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(arr[index].begin(), arr[index].end(), snap_id);
        if (it == arr[index].begin()) return 0;

        return m[index][*prev(it)];
    }
};

