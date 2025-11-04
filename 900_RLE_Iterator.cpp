class RLEIterator {
public:
    vector<int> v;
    int i = 0;
    int total;

    RLEIterator(vector<int>& encoding) {
        v = encoding;
    }
    
    int next(int n) {
        while (i < v.size()) {
            if (n < v[i]) {
                v[i] -= n;
                return v[i+1];
            }
            else if (n == v[i]) {
                i += 2;
                return v[i-1];
            }
            else {
                n -= v[i];
                i += 2;
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
