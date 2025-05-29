class SmallestInfiniteSet {
public: 
    int cur;
    set<int> s;
    SmallestInfiniteSet() {
        cur = 1;
    }
    
    int popSmallest() {
        if (s.size()) {
            int i = *s.begin();
            s.erase(i);
            return i;
        }
        
        return cur++;
    }
    
    void addBack(int num) {
        if (num < cur) s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
