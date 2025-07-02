class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int idx = 0;
        int min_diff = INT_MAX;

        for (int i = 0; i < n ; i++) {
            if (abs(arr[i] - x) < min_diff) {
                min_diff = abs(arr[i] - x);
                idx = i; 
            }
        }        

        int l = idx-1, r = idx+1;
        while (r - l - 1 < k) {
            if (l < 0) {
                r++;
            }
            else if (r >= n) {
                l--;
            }
            else if (abs(arr[l] - x) <= abs(arr[r] - x)) {
                l--;
            }
            else {
                r++;
            }
        }

        vector<int> ans;
        for (int i = l+1; i <= r-1; i++) {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};
