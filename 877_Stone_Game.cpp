class Solution {
public:
    pair<int, int> memo[501][501];

    pair<int, int> solve(vector<int>& piles, int left, int right) {
        if (left > right) return {0,0};
        if (memo[left][right].first != 0) return memo[left][right];

        pair<int, int> take_left = solve(piles, left+1, right);
        pair<int, int> take_right = solve(piles, left, right-1);

        if (take_left.second + piles[left] > take_right.second + piles[right]) {
            return memo[left][right] = {take_left.second + piles[left], take_left.first};
        }
        else {
            return memo[left][right] = {take_right.second + piles[right], take_right.first};
        }
    }

    bool stoneGame(vector<int>& piles) {
        auto [alice, bob] = solve(piles, 0, piles.size()-1);
        return alice > bob;
    }
};

// the number of piles is even
// the total number of stones is odd
// each turn, they can only pick the first tile or the last pile

// 5,3,4,5
