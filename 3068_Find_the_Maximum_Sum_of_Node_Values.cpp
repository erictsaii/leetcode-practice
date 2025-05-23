using ll = long long;
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll sum = 0;
        vector<int> diff;
        for (auto& n : nums) {
            sum += n;
            int after_xor = n ^ k;
            diff.push_back(after_xor - n);
        }
        sort(diff.rbegin(), diff.rend()); // decreasing

        for (int i = 0; i < diff.size()-1; i += 2) {
            if (diff[i] + diff[i+1] > 0) sum += diff[i] + diff[i+1];
        }

        return sum;
    }
};

// tree
// xor操作僅限於parent跟child之間，要兩個一起，不限次數
// xor基數次才有效果，偶數次還原

// 用兩node xor完之後跟地原本差做排序


// ans: 因為xor有還原的特性，且tree一定是connected
// 所以只要被xor的node個數是偶數個就可以了(題目規定一次xor就要xor一個pair)