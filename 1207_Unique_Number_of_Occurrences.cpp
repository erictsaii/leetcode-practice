class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> frequency;
        unordered_map<int, bool> num_of_occurrences;

        for(auto& a : arr) frequency[a]++;

        for(auto& f : frequency) {
            if (num_of_occurrences.find(f.second) != num_of_occurrences.end()) return false;
            num_of_occurrences[f.second] = true;
        }

        return true;
    }
};