class StockSpanner {
public:
    stack<pair<int, int>> stk; // idx, val
    int len;
    StockSpanner() {
        len = 0;
    }
    
    int next(int price) {
        while (!stk.empty() && stk.top().second <= price) stk.pop();

        int rtn = (stk.empty()) ? (len + 1) : (len - stk.top().first);

        stk.push({len, price});
        len++;

        return rtn;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
