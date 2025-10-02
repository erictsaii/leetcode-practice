class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int full_bottles = numBottles;
        int empty_bottles = 0;

        int ans = 0;
        while (full_bottles != 0) {
            ans += full_bottles;
            empty_bottles += full_bottles;
            full_bottles = 0;
            while (empty_bottles >= numExchange) {
                full_bottles++;
                empty_bottles -= numExchange;
                numExchange++;
            }
        }
        return ans;
    }
};
