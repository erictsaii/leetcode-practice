class Solution {
public:
    int numberOfWays(string corridor) {
        int seats = 0;
        for (auto& c : corridor) if (c == 'S') seats++;

        if (seats & 1 || seats == 0) return 0;

        while (corridor.back() == 'P') corridor.pop_back();

        seats = 0;
        int plants;
        long long ans = 1;
        int MOD = 1e9+7;
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                seats++;
            }
            if (seats == 2) {
                i++;
                plants = 0;
                while (corridor[i] == 'P') {
                    plants++;
                    i++;
                }
                ans *= (plants + 1); 
                ans %= MOD;
                seats = 1;
            }
        }
        return ans;
    }
};


// a section need exactly two seats with any number of plants

// for every two 'S', they need to gruop together
// if 'S' is odd, return 0


// SS | P | P | SPS  = 3

// PP SPS P
