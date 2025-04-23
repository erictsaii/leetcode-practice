class Solution {
    public:
        int countLargestGroup(int n) {
            unordered_map<int, int> group;
    
            for (int i = 1; i <= n; i++) {
                int sum = 0;
                int curr = i;
                while (curr != 0) {
                    sum += curr % 10;
                    curr /= 10;
                }
                group[sum]++;
            }
    
            int ans = 0, max_group_size = 0;
            for (auto i : group) {
                if (i.second > max_group_size) {
                    max_group_size = i.second;
                    ans = 1;
                }
                else if (i.second == max_group_size) {
                    ans++;
                }
            }
    
            return ans;
        }
    };