class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (int i = 0; i < asteroids.size(); i++) {
            if (ans.size() == 0 || ans.back() < 0 || ans.back() > 0 && asteroids[i] > 0) ans.push_back(asteroids[i]);
            else {
                while (ans.size() > 0 && -asteroids[i] > ans.back() && ans.back() > 0) ans.pop_back();
                if (ans.size() > 0 && -asteroids[i] == ans.back() && ans.back() > 0) ans.pop_back();
                else if (ans.size() == 0 || (ans.size() > 0 && ans.back() < 0)) ans.push_back(asteroids[i]);
            }
        }

        return ans;
    }
};