class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while(1) {
            int size = word.size();
            for (int i = 0; i < size; i++) {
                if (word[i] == 'z') word.push_back('a');
                else word.push_back(word[i] + 1);
            }
            if (word.size() >= k) break;
        }
        return word[k - 1];
    }
};
