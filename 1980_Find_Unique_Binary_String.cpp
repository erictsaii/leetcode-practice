class Solution {
    public:
        string ans = "";
        void dfs(int n, int idx, string tmp, unordered_map<string, int> m) {
            if (idx == n) {
                if (m[tmp] == 0) ans = tmp;
                return;
            }
            if (ans != "") return;
    
            dfs(n, idx+1, tmp+"0", m);
            dfs(n, idx+1, tmp+"1", m);
        }
        string findDifferentBinaryString(vector<string>& nums) {
            int n = nums.size();
            unordered_map<string, int> m;
            for (auto num : nums) {
                m[num]++;
            }
            dfs(n, 0, "", m);
            return ans;
        }
    };