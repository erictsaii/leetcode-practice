class Solution {
public:
    string intToRoman(int num) {
        vector<int> v = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        unordered_map<int, string> m;
        m[1000] = "M";
        m[900] = "CM";
        m[500] = "D";
        m[400] = "CD";
        m[100] = "C";
        m[90] = "XC";
        m[50] = "L";
        m[40] = "XL";
        m[10] = "X";
        m[9] = "IX";
        m[5] = "V";
        m[4] = "IV";
        m[1] = "I";

        string ans = "";
        for (int i = 0; i < v.size(); i++) {
            while (num >= v[i]) {
                num -= v[i];
                ans.append(m[v[i]]);
            }
        }
        return ans;
    }
};
