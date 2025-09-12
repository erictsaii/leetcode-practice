class Solution {
public:
    bool is_vowel(char& c) {
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }

    bool doesAliceWin(string s) {
        for (auto& c : s) {
            if (is_vowel(c)) return true;
        }
        return false;
    }
};
