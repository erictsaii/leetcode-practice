class Solution {
    public:
        bool check(vector<int>& power, int sum, int pos, int n) {
            if (pos == power.size()){
                if (sum == n) return true;
                else return false;
            }
            else {
                return check(power, sum + power[pos], pos+1, n) || check(power, sum, pos+1, n);
            }
        }
        bool checkPowersOfThree(int n) {
            vector<int> power;
            int tmp = 1;
            while(tmp <= n) {
                power.push_back(tmp);
                tmp *= 3;
            }
            return check(power, 0, 0, n);
        }
    };