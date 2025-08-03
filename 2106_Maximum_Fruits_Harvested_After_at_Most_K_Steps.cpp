class Solution {
public:
    int min_steps(int left, int right, int startPos) {
        return min(abs(startPos - left), abs(startPos - right)) + (right - left);
    }

    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int start = 0;
        int sum = 0;
        int ans = 0;

        for (int end = 0; end < fruits.size(); end++) {
            sum += fruits[end][1];
            while (start <= end && min_steps(fruits[start][0], fruits[end][0], startPos) > k) {
                sum -= fruits[start][1];
                start++;
            }
            ans = max(ans, sum);
        }

        return ans;
    }
};
