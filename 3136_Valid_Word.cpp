class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;

        unordered_set<char> vowel({'a', 'e', 'i', 'o', 'u'});
        int vowel_cnt = 0, consonant_cnt = 0;
        for (auto& c : word) {
            if (!isdigit(c) && !isalpha(c)) return false;
            if (isdigit(c)) continue;
            if (vowel.count(tolower(c))) {
                vowel_cnt = 1;
            }
            else {
                consonant_cnt = 1;
            }
        }

        return vowel_cnt && consonant_cnt;
    }
};
