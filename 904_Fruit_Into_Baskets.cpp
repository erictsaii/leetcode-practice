class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        unordered_map<int, int> m;

        int start = 0;
        for (int end = 0; end < fruits.size(); end++) {
            m[fruits[end]]++;
            while (m.size() >= 3) {
                m[fruits[start]]--;
                if (m[fruits[start]] == 0) m.erase(fruits[start]);
                start++;
            }
            ans = max(ans, end - start + 1);
        }

        return ans;
    }
};
