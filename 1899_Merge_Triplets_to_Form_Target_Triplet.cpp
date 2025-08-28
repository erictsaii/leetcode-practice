class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool a, b, c;
        a = b = c = false;

        for (auto& triplet : triplets) {
            if (triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]) {
                if (triplet[0] == target[0]) a = true;
                if (triplet[1] == target[1]) b = true;
                if (triplet[2] == target[2]) c = true;
            }
        }

        return a && b && c;
    }
};
