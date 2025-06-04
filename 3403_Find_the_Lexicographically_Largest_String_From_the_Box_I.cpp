class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;
        int n = word.size();
        int len = n - numFriends + 1;
        string ans = "";

        for (int i = 0; i < n; i++) {
            string tmp = word.substr(i, len);

            ans = max(ans, tmp);
        }

        return ans;
    }
};
