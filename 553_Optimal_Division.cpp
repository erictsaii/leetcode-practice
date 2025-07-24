class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ans;
        if (nums.size() == 1) return to_string(nums[0]);
        else if (nums.size() == 2) {
            ans.append(to_string(nums[0]));
            ans.push_back('/');
            ans.append(to_string(nums[1]));
            return ans;
        }

        ans.append(to_string(nums[0]));
        ans.append("/(");
        ans.append(to_string(nums[1]));

        for (int i = 2; i < nums.size(); i++) {
            ans.push_back('/');
            ans.append(to_string(nums[i]));
        }
        ans.push_back(')');
        return ans;
    }
};
