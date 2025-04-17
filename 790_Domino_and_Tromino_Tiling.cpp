class Solution {
    public:
        long long MOD = 1e9 + 7;
        int numTilings(int n) {
            vector<long long> full(n+3);
            vector<long long> not_full(n+3); 
    
            full[0] = 1;
            full[1] = 1;
            full[2] = 2;
            not_full[0] = 1;
            not_full[1] = 1;
            not_full[2] = 2;
    
            for (int i = 3; i <= n; i++) {
                // full
                // full i-1: 只能放直的
                // full i-2: 只能放兩個橫的
                // not full i-1: 放一個相對應的tromino
                full[i] = (full[i-1] + full[i-2] + not_full[i-1]) % MOD;
    
                // not full
                // full i-2: 可以放兩種tromino
                // not full i-1: 可以放一條橫的
                not_full[i] = (2*full[i-2] + not_full[i-1]) % MOD;
            }
           
            return full[n];
        }
    };