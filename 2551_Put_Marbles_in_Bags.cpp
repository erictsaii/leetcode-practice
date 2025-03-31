class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) {
            if (weights.size() == k) return 0;
            vector<int> sum_weights(weights.size()-1);
            for (int i = 0; i < weights.size()-1; i++) {
                sum_weights[i] = weights[i] + weights[i+1];
            }
            sort(sum_weights.begin(), sum_weights.end());
            long long min_sum = 0, max_sum = 0;
            for (int i = 0; i < k-1; i++) {
                min_sum += sum_weights[i];
                max_sum += sum_weights[sum_weights.size()-1 - i];
            }
    
            return max_sum - min_sum;
        }
    };
    