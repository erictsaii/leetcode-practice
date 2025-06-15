class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {
    }
    
    void addNum(int num) {
        if (!left.size() && !right.size()) {
            left.push(num);
            return;
        }

        if (num > findMedian()) right.push(num);
        else left.push(num);

        if (left.size() > right.size()+1) {
            right.push(left.top());
            left.pop();
        }

        if (left.size() < right.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if (left.size() > right.size()) return left.top();
        else return (left.top() + right.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// two pq
// ()  1  ()
// ()  1  (2)
// (1)    (2)  1.5
// (1 2)  (3)  2
// (1 2)  (3 4) 2.5

// (-1)  ()
// (-2) (-1)
// (-3 -2) (-1)
// (-4 -3) (-2 -1)
