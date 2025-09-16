using ll = long long;
class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        ll now;

        for (int i = 0; i < nums.size(); i++) {
            now = nums[i];

            while (ans.size() > 0) {
                int top = ans.back();
                int result = gcd(now, top);

                if (result == 1) break;
                else {
                    ans.pop_back();
                    now = 1LL * now * top / result;
                }
            }

            ans.push_back(now);
        }
        return ans;
    }
};
