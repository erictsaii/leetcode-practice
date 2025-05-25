class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> m;

        for (auto& word : words) m[word]++;

        int ans = 0;
    
        for (auto mi : m) {
            string r = mi.first;
            reverse(r.begin(), r.end());

            if (mi.first == r) {
                ans += (mi.second/2) * 2 * 2;
                m[mi.first] -= (mi.second/2) * 2;
            }
            else {
                if (m.find(r) != m.end()) {
                    int min_times = min(m[mi.first], m[r]);
                    ans += 2*2*min_times;
                    m[mi.first] -= min_times;
                    m[r] -= min_times;
                }
            }
        }

        for (auto mi : m) {
            if (mi.second >= 1 && mi.first[0] == mi.first[1]) {
                ans += 2;
                break;
            }
        }

        return ans;
    }
};

// two lowercase for each word
// pick some elements
// in any order
// at most once