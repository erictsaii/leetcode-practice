class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; i++) gas[i] -= cost[i];

        int sum = 0;
        int start_idx = 0;
        for (int i = 0; i < n-1; i++) {
            sum += gas[i];
            if (sum < 0) {
                sum = 0;
                start_idx = i+1;
            }
        }

        sum = 0;
        bool possible = true;
        for (int i = 0; i < n; i++) {
            sum += gas[(i+start_idx)%n];
            if (sum < 0) possible = false;
        }
        
        return possible ? start_idx : -1;
    }
};


// starting point有什麼特質?
// 一定要是正的
// 只有一個
