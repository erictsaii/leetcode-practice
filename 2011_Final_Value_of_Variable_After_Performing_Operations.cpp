class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        unordered_map<string, int> m;
        m["--X"] = -1;
        m["X--"] = -1;
        m["++X"] = 1;
        m["X++"] = 1;

        int ans = 0;
        for (auto& op : operations) {
            ans += m[op];
        }
        return ans;
    }
};
