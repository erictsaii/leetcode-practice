class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        multiset<int> s;
        for (auto& h : hand) s.insert(h);

        while (!s.empty()) {
            int curr = *s.begin();

            for (int i = 1; i < groupSize; i++) {
                if (!s.count(curr+i)) return false;
            }

            for (int i = 0; i < groupSize; i++) {
                s.erase(s.find(curr+i));
            }
        }

        return true;
    }
};
