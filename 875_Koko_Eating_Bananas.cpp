class Solution {
public:
    bool valid(vector<int>& piles, int h, int speed) {
        int tmp;
        long long cnt = 0;
        for (auto&p : piles) {
            tmp = p / speed;
            if (p % speed != 0) tmp++;
            cnt += tmp;            
        }
        return h >= cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9;
        int ans = 0;
        while (l <= r) {
            int mid = (l+r) / 2;
            if (valid(piles, h, mid)){
                r = mid - 1;
                ans = mid;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
