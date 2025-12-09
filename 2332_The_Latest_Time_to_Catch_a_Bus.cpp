class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        unordered_set<int> all_time;
        priority_queue<int, vector<int>, greater<>> pq;
        for (auto& passenger : passengers) {
            all_time.insert(passenger);
            pq.push(passenger);
        }

        sort(buses.begin(), buses.end());

        int quota;
        for (int i = 0; i < buses.size()-1; i++) {
            quota = capacity;
            while (quota && pq.size() && pq.top() <= buses[i]) {
                quota--;
                pq.pop();
            }
        }

        // the last bus
        quota = capacity;
        int latest_passenger = -1;
        while (quota && pq.size() && pq.top() <= buses.back()) {
            quota--;
            latest_passenger = pq.top();
            pq.pop();
        }
        if (quota) latest_passenger = max(latest_passenger, buses.back());

        while (all_time.count(latest_passenger)) {
            latest_passenger--;
        }
        return latest_passenger;
    }
};


// this question could be turned into:
// the latest arrival time to get the last seat of the last bus
// + we could not have the same arrival time as another passenger
