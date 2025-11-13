class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;
        if (finalSum & 1) return ans;
        long long i = 2;
        long long curr = 0;

        while (curr + i <= finalSum) {
            curr += i;
            ans.push_back(i);
            i += 2;
        }

        int n = ans.size();
        ans[n-1] += finalSum - curr;
        return ans;
    }
};
