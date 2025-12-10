class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());

        unordered_map<int, int> freq;
        for (auto& num : changed) freq[num]++;

        vector<int> ans;
        for (int i = 0; i < changed.size(); i++) {
            if (!freq[changed[i]]) continue;
            if (!freq[changed[i]*2] || changed[i]==0 && freq[0]==1) return {};

            freq[changed[i]*2]--;
            freq[changed[i]]--;

            ans.push_back(changed[i]);
        }
        return ans;
    }
};
