class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> v(n); // nums2, num1

        for (int i = 0; i < n; i++) v[i] = {nums2[i], nums1[i]};

        sort(v.begin(), v.end());

        priority_queue<int, vector<int>, greater<int>> q;
        long long sum = 0, ans = 0;
        for (int i = n-1; i >= 0; i--) {
            // init priority queue
            if (q.size() < k-1) {
                sum += v[i].second;
                q.push(v[i].second);
                continue;
            }

            sum += v[i].second;
            q.push(v[i].second);

            ans = max(ans, 1LL * v[i].first * sum);
            
            sum -=  q.top();
            q.pop();
        }
        return ans;
    }
};

// subsequence 可以是不連續
// 要先固定一邊
