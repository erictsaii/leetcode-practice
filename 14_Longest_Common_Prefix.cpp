class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;

        for (int i = 0; i < strs[0].size(); i++) {

            for (auto& str : strs) {
                if (i >= str.size()) return ans;
                if (str[i] != strs[0][i]) return ans;
            }

            ans.push_back(strs[0][i]);
        } 

        return ans;
    }
};
