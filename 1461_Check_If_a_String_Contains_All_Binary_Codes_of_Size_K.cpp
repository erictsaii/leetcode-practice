class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> total;
        
        for (int end = 0; end < s.size(); end++) {
            if (end - k + 1 < 0) continue;

            total.insert(s.substr(end - k + 1, k));
        }

        return total.size() == pow(2, k);
    }
};
