class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (auto& c : tasks) freq[c-'A']++;

        vector<int> last_idx(26, -n);
        int ans = 0;
        int total = tasks.size();

        while (total != 0) {
            int to_put_idx = -1;
            int to_put_freq = 0;
            for (int i = 0; i < 26; i++) {
                if (freq[i] > to_put_freq && ans - last_idx[i] > n) {
                    to_put_idx = i;
                    to_put_freq = freq[i];
                }
            }
            if (to_put_idx != -1) {
                freq[to_put_idx]--;
                last_idx[to_put_idx] = ans;
                total--;
            }
            ans++;
        }


        return ans-1;
    }
};
