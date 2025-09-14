class Solution {
public:
    string string_to_lower(const string& s) {
        string result;
        for (int i = 0; i < s.size(); i++) {
            result.push_back(tolower(s[i]));
        }
        return result;
    }

    string all_vowel_to_star(const string& s) {
        string result = s;
        for (int i = 0; i < s.size(); i++) {
            if (is_vowel(result[i])) result[i] = '*';
        }
        return result;
    }

    bool is_vowel(const char& c) {
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactly_same;
        unordered_map<string, int> all_lower; // lower string, idx in wordlist
        unordered_map<string, int> with_stars; // change all vowels to star, idx in wordlist

        for (int i = 0; i < wordlist.size(); i++) {
            exactly_same.insert(wordlist[i]);

            string tmp = string_to_lower(wordlist[i]);
            if (all_lower.find(tmp) == all_lower.end()) {
                all_lower[tmp] = i;
            }

            tmp = all_vowel_to_star(tmp);
            if (with_stars.find(tmp) == with_stars.end()) {
                with_stars[tmp] = i;
            }
        }

        vector<string> ans;
        for (auto& q : queries) {
            if (exactly_same.count(q)) {
                ans.push_back(q);
                continue;
            }

            string tmp = string_to_lower(q);
            if (all_lower.find(tmp) != all_lower.end()) {
                ans.push_back(wordlist[all_lower[tmp]]);
                continue;
            }

            tmp = all_vowel_to_star(tmp);
            if (with_stars.find(tmp) != with_stars.end()) {
                ans.push_back(wordlist[with_stars[tmp]]);
                continue;
            }

            ans.push_back("");
        }

        return ans;
    }
};

// 也有可能exactly match
