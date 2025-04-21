class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            long long _max = 0, _min = 0;
            long long sum = 0;
            for (int i = 0; i < differences.size(); i++) {
                sum += differences[i];
                _max = max(_max, sum);
                _min = min(_min, sum);
            }
            _max -= _min - lower;
    
            int ans = upper - _max + 1;
            return (ans > 0) ? ans : 0;
        }
    };
    
    
    