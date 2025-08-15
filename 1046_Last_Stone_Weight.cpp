class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto& stone : stones) {
            pq.push(stone);
        }

        while (pq.size() >= 2) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            y -= x;

            if (y != 0) pq.push(y);
        }

        return (pq.size()==1) ? pq.top() : 0;
    }
};
