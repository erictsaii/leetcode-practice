class Solution {
public:
    class Node {
        public:
            Node* next[26] = {};
            int is_word;
            int prefix_cnt;
            Node() {
                is_word = 0;
                prefix_cnt = 0;
            }
    };

    vector<int> sumPrefixScores(vector<string>& words) {
        Node* dummy = new Node();
        Node* curr;
        for (auto& word : words) {
            curr = dummy;
            for (auto& c : word) {
                if (!curr->next[c-'a']) curr->next[c-'a'] = new Node();
                curr = curr->next[c-'a'];
                curr->prefix_cnt++;
            }
        }

        int n = words.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            curr = dummy;
            for (auto& c : words[i]) {
                curr = curr->next[c-'a'];
                ans[i] += curr->prefix_cnt;
            }
        }
        return ans;
    }
};


// trie
