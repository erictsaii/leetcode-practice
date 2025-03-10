class Solution {
    public:
        bool is_vowel(char a) {
            if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') return true;
            return false;
        }
        long long at_least_k(string word, int k) {
            int l = 0, r = 0;
            unordered_map<char, int> vowel;
            int consonant = 0;
            long long result = 0;
    
            while (r < word.size()) {
                if (is_vowel(word[r])) {
                    vowel[word[r]]++;
                }
                else {
                    consonant++;
                }
                while (vowel.size() == 5 && consonant >= k) {
                    result += word.size() - r;
                    if (is_vowel(word[l])) {
                        vowel[word[l]]--;
                        if (vowel[word[l]] == 0) vowel.erase(word[l]);
                    }
                    else {
                        consonant--;
                    }
                    l++;
                }
                r++; 
            }
            return result;
        }
        long long countOfSubstrings(string word, int k) {
            return at_least_k(word, k) - at_least_k(word, k+1);
        }
    };
    