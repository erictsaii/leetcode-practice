class Solution {
public:
    string sortVowels(string s) {
        vector<char> v;
        for (auto& c : s) {
            char x = tolower(c);
            if (x=='a' || x=='e' || x=='i' || x=='o' || x=='u') {
                v.push_back(c);
            }
        }
        sort(v.begin(), v.end());

        int idx = 0;
        for (int i = 0; i < s.size(); i++) {
            char x = tolower(s[i]);
            if (x=='a' || x=='e' || x=='i' || x=='o' || x=='u') {
                s[i] = v[idx++];
            }
        }
        return s;
    }
};
