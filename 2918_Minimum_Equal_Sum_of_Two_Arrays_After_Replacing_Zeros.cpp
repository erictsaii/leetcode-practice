class Solution {
    public:
        long long minSum(vector<int>& nums1, vector<int>& nums2) {
            long long sum1 = 0, sum2 = 0, zero1 = 0, zero2 = 0;
    
            // calculate sum,zeros of nums1 and nums2 
            for (auto n : nums1) {
                sum1 += n;
                if (n == 0) zero1++;
            }
            
            for (auto n : nums2) {
                sum2 += n;
                if (n == 0) zero2++;
            }
    
            // impossible case
            if (zero2 == 0 && sum1+zero1 > sum2) return -1;
            if (zero1 == 0 && sum2+zero2 > sum1) return -1;
    
            return max(sum1+zero1, sum2+zero2);
        }
    };
    
    // we have to replace all 0's with positive integers
    // find minimum equal sum