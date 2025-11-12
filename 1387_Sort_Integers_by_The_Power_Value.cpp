class Solution {
public:
    unordered_map<int, int> memo; // x, power 

    int dfs(int x) {
        if (x == 1) return 0;
        if (memo.count(x)) return memo[x];

        int result;
        if (x & 1) result = 1 + dfs(3*x + 1);
        else result = 1 + dfs(x/2);

        return memo[x] = result;  
    }

    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> v;

        for (int i = lo; i <= hi; i++) {
            v.push_back({dfs(i), i});
        }

        sort(v.begin(), v.end());

        return v[k-1].second;
    }
};
