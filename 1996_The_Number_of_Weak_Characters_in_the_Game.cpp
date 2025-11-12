class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }

    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), cmp);

        stack<pair<int, int>> stk; // atk, def
        int ans = 0;
        for (int i = 0; i < properties.size(); i++) {
            while (stk.size() && stk.top().first < properties[i][0] && stk.top().second < properties[i][1]) {
                ans++;
                stk.pop();
            }
            stk.push({properties[i][0], properties[i][1]});
        }
        return ans;
    }
};

// naive: O(n^2)

// sort + monotonic stack?
// 3 6   5 5   6 3

// [[1,2],[1,1],[2,2],[2,1]]
// O(nlogn)

// could be further optimized to space O(1)
