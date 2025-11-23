class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int ans = 0;
        priority_queue<int> one;
        priority_queue<int> two;

        for (auto& num : nums) {
            ans += num;
            if (num % 3 == 1) {
                one.push(num);
                if (one.size() > 2) one.pop();
            }
            else if (num % 3 == 2) {
                two.push(num);
                if (two.size() > 2) two.pop();
            }
        } 

        int remain = ans % 3;
        if (remain == 0) return ans;
        
        if (remain == 1) {
            int sub_one = 1e9;
            if (one.size() == 2) {
                one.pop();
                sub_one = one.top();
            }
            else if (one.size() == 1) {
                sub_one = one.top();
            }

            int sub_two = 1e9;
            if (two.size() == 2) {
                sub_two = two.top();
                two.pop();
                sub_two += two.top();
            }
            return (sub_one > sub_two) ? ans - sub_two : ans - sub_one;
        }

        // remain == 2
        int sub_one = 1e9;
        if (one.size() == 2) {
            sub_one = one.top();
            one.pop();
            sub_one += one.top();
        }

        int sub_two = 1e9;
        if (two.size() == 2) {
            two.pop();
            sub_two = two.top();
        }
        else if (two.size() == 1) {
            sub_two = two.top();
        }
        return (sub_one > sub_two) ? ans - sub_two : ans - sub_one;
    }
};
