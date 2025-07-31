class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        unordered_set<int> prev;

        for (int i = 0; i < arr.size(); i++) {
            unordered_set<int> curr;
            curr.insert(arr[i]);
            for (auto& num : prev) {
                curr.insert(num | arr[i]);
            }
            for (auto& num : curr) {
                ans.insert(num);
            }
            prev = curr;
        }

        return ans.size();
    }
};
