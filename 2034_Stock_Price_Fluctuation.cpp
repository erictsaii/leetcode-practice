class StockPrice {
public:
    unordered_map<int, int> m; // timestamp, price
    int latest_timestamp;
    priority_queue<pair<int, int>> max_pq; // price, timestamp
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_pq; 

    StockPrice() {
        latest_timestamp = 0;
    }

    void update(int timestamp, int price) {
        m[timestamp] = price;
        max_pq.push({price, timestamp});
        min_pq.push({price, timestamp});
        latest_timestamp = max(latest_timestamp, timestamp);
    }

    int current() {
        return m[latest_timestamp];
    }

    int maximum() {
        while (m[max_pq.top().second] != max_pq.top().first) {
            max_pq.pop();
        }
        return max_pq.top().first;
    }

    int minimum() {
        while (m[min_pq.top().second] != min_pq.top().first) {
            min_pq.pop();
        }
        return min_pq.top().first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
