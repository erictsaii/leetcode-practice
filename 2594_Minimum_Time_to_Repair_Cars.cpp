class Solution {
    public:
        bool valid(vector<int>& ranks, int cars, long long guess) {
            int cnt = cars;
    
            for (int i = 0; i < ranks.size(); i++) {
                cnt -= (int)sqrt(guess / ranks[i]);
                if (cnt <= 0) return true;
            }
    
            return false;
        }
        long long repairCars(vector<int>& ranks, int cars) {
            long long ans = 0;
            long long l = 0;
            long long r = 1LL * (*max_element(ranks.begin(), ranks.end())) * cars * cars;
            long long mid;
    
            while (l <= r) {
                mid = (l + r) / 2;
                if (valid(ranks, cars, mid)) {
                    ans = mid;
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
    
            return ans;
        }
    };