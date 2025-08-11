class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> powers;
        int p = 1;
        while (n != 0) {
            if (n & 1) powers.push_back(p);
            p <<= 1;
            n >>= 1;
        }

        vector<int> ans;
        long long MOD = 1e9 + 7;
        for (auto& q : queries) {
            long long product = 1;
            for (int i = q[0]; i <= q[1]; i++) {
                product *= powers[i];
                product %= MOD;
            }
            ans.push_back(product);
        }

        return ans;
    }
};
